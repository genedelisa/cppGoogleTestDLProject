# set minimum cmake version
cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

# create a static library and an executable with a main that uses it

message("cmake source in ${CMAKE_CURRENT_SOURCE_DIR}")
set(Source
    Account.cpp
    ../include/Account.hpp
)

#####################################################################
# create a static library
set(TheLibraryName accountLib)
add_library(${TheLibraryName} STATIC ${Source})

# target_compile_features(${TheLibraryName} PUBLIC "cxx_std_17")

# https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(${TheLibraryName} PUBLIC
# this doesnt work	${CMAKE_CURRENT_SOURCE_DIR}../include
	"../include"
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}../include>
	$<INSTALL_INTERFACE:../include>
)


#####################################################################
# create the executable
add_executable(account
    main.cpp
)

# link the library to the executable
# https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(account
    PRIVATE ${TheLibraryName}
)

set_target_properties(${theProgramName} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

include(CMakePrintHelpers)
cmake_print_properties(
    TARGETS 
        account
    PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY 
)









#add_library(record STATIC src/include/record.cpp)
#target_include_directories(record PUBLIC src/include/record)  # When cmakeDemo links to this, it'll get these includes
#target_include_directories(record PRIVATE src/include/record/lib)   # When cmakeDemo links to this, it won't get these includes


#target_include_directories(${TheLibraryName} PUBLIC
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${TheLibraryName}>
#  $<INSTALL_INTERFACE:include/${TheLibraryName}>  # <prefix>/include/${TheLibraryName}
#)
