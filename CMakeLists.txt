# set minimum cmake version
cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

project(cppGoogleTestDLProject
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "CMake with auto-downloaded googletest project for C++17."
    HOMEPAGE_URL "https://github.com/genedelisa/cppGoogleTestDLProject"
)

message("top level cmake ${PROJECT_SOURCE_DIR}")

# for debugging cmake files
include(CMakePrintHelpers)
# https://cmake.org/cmake/help/latest/module/CMakePrintHelpers.html


#####################################################################
# Options
# https://cmake.org/cmake/help/latest/command/option.html

# e.g. cmake -D USE_UNIT_TESTING=ON ..
option(USE_UNIT_TESTING "Build the tests" OFF)
option(GENERATE_DOC "Run Doxygen to generate docs" OFF)
# possible incantation:
# cd build && cmake -D USE_UNIT_TESTING=ON -D GENERATE_DOC=ON .. && make
#####################################################################

if(USE_UNIT_TESTING)
	message("Downloading Google Test")

	# this will download and build google test into build
	#####################################################################
	# Download and unpack googletest at configure time
	configure_file(CMake/GoogleTest.txt.in googletest-download/CMakeLists.txt)
	execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
	if (result)
    	message(FATAL_ERROR "CMake step for googletest failed: ${result}")
	endif ()
	execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
	if (result)
    	message(FATAL_ERROR "Build step for googletest failed: ${result}")
	endif ()

	# Prevent overriding the parent project's compiler/linker
	# settings on Windows
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

	# Add googletest directly to our build. This defines
	# the gtest and gtest_main targets.
	add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

	# The gtest/gtest_main targets carry header search path
	# dependencies automatically when using CMake 2.8.11 or
	# later. Otherwise we have to add them here ourselves.
	if (CMAKE_VERSION VERSION_LESS 2.8.11)
    	include_directories("${gtest_SOURCE_DIR}/include")
	endif ()

endif(USE_UNIT_TESTING)

#####################################################################
# where to put the output. Otherwise the main will be in src and the test in test.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#####################################################################
# Now the config specific for this project
#
# each of these dirs have a CMakeLists.txt
add_subdirectory(src)
add_subdirectory(app)

#####################################################################
if(USE_UNIT_TESTING)
  message("Configuring project testing")
  # well, duh
  enable_testing()
  add_subdirectory(test)
endif(USE_UNIT_TESTING)

if(GENERATE_DOC)
  add_subdirectory(doc)
endif(GENERATE_DOC)
