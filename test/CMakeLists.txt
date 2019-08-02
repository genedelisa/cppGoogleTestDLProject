# set minimum cmake version
cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

include(googletest)

set(Source
    main_tests.cpp
)

# since we use the name multiple times here
set(TheTestTarget tests)

add_executable(${TheTestTarget}
    ${Source}
)

target_compile_features(${TheTestTarget}
	PRIVATE
		cxx_std_17
)

# link the library to the executable using the alias
# https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(${TheTestTarget}
	PUBLIC
        # this is the alias
        GEND::accountLib
        gtest
        gtest_main
		#${Boost_LIBRARIES}
)

target_compile_features(${TheTestTarget}
	PRIVATE
		cxx_std_17
)

target_compile_options(${TheTestTarget}
	PRIVATE
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:Clang>:-Wall>
    	$<$<CXX_COMPILER_ID:GNU>:-Wall>
)

# https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(${TheTestTarget} 
    PUBLIC
        $<INSTALL_INTERFACE:include/gend>
        $<BUILD_INTERFACE:${GEND_INCLUDE_BUILD_DIR}>

    PRIVATE
        #${CMAKE_CURRENT_SOURCE_DIR}/include/
)


# https://cmake.org/cmake/help/latest/command/target_link_options.html
target_link_options(${TheTestTarget}
    PUBLIC
    "$<$<CONFIG:DEBUG>:${-v}>"
    #    -DBOOST_LOG_DYN_LINK
)


gtest_discover_tests(${TheTestTarget})
