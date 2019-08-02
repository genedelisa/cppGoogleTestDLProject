# set minimum cmake version
cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

set(GEND_INCLUDE_BUILD_DIR "${PROJECT_SOURCE_DIR}/include/")
message("cmake GEND_INCLUDE_BUILD_DIR in ${GEND_INCLUDE_BUILD_DIR}")

# create a static library and an executable with a main that uses it

message("cmake CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}")
set(Source
    Account.cpp
)

#####################################################################
# create a static library
set(TheLibraryName accountLib)

add_library(${TheLibraryName} STATIC ${Source})
add_library(GEND::accountLib ALIAS accountLib)

target_compile_features(${TheLibraryName} 
	PRIVATE
		cxx_std_17
)

# https://cmake.org/cmake/help/latest/command/target_include_directories.html

target_include_directories(${TheLibraryName} 
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${GEND_INCLUDE_BUILD_DIR}>

    PRIVATE
        #${CMAKE_CURRENT_SOURCE_DIR}/include/
)

 
# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html
target_compile_options(${TheLibraryName} 
	PRIVATE

    "$<$<CXX_COMPILER_ID:AppleClang>:-Wall>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-Wextra>"
    "$<$<CXX_COMPILER_ID:AppleClang>:-pedantic>"

    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-g3>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-O0>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-fno-omit-frame-pointer>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-DDEBUG>"

    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-DNDEBUG>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-O3>"


    $<$<CXX_COMPILER_ID:Clang>:-Wall>
    $<$<CXX_COMPILER_ID:Clang>:-Wextra>
    $<$<CXX_COMPILER_ID:Clang>:-pedantic>        

    $<$<CXX_COMPILER_ID:MSVC>:/W3>

    $<$<CXX_COMPILER_ID:GNU>:-Wall>
    $<$<CXX_COMPILER_ID:GNU>:-Wextra>
    $<$<CXX_COMPILER_ID:GNU>:-pedantic>
)

# https://cmake.org/cmake/help/latest/command/target_link_options.html
target_link_options(${TheLibraryName}  
    PUBLIC 
        "$<$<CONFIG:DEBUG>:${-v}>"
)


include(CMakePrintHelpers)

cmake_print_properties(
    TARGETS 
        ${TheLibraryName} 
    PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY         
)
cmake_print_variables(
    CMAKE_MAJOR_VERSION
    CMAKE_MINOR_VERSION
    CMAKE_CURRENT_SOURCE_DIR
    GEND_INCLUDE_BUILD_DIR
)
