cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

set(Source
    theApp.cpp
)

#####################################################################
# create the executable
add_executable(theApp
    ${Source}
)

target_compile_features(theApp
	PRIVATE
		cxx_std_17
)

# link the library to the executable using the alias
target_compile_options(theApp
	PRIVATE
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:Clang>:-Wall>
    	$<$<CXX_COMPILER_ID:GNU>:-Wall>
)

# link the library to the executable
# https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(theApp
	PUBLIC
        # this is the alias
        GEND::accountLib
		#${Boost_LIBRARIES}
)


# https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(theApp 
    PUBLIC
        $<INSTALL_INTERFACE:include/gend>
        $<BUILD_INTERFACE:${GEND_INCLUDE_BUILD_DIR}>

    PRIVATE
        #${CMAKE_CURRENT_SOURCE_DIR}/include/
)


# https://cmake.org/cmake/help/latest/command/target_link_options.html
target_link_options(theApp
    PUBLIC
    "$<$<CONFIG:DEBUG>:${-v}>"
    #    -DBOOST_LOG_DYN_LINK
)

set_target_properties(theApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

cmake_print_properties(
    TARGETS 
        theApp
    PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY 
)
