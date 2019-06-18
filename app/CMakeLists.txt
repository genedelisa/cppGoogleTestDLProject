cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

set(Source
    theApp.cpp
)

#####################################################################
# create the executable
add_executable(theApp
    ${Source}
)

# link the library to the executable
# https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(theApp
    PRIVATE accountLib
)

# how to set properties. This has actually already been set.
set_target_properties(theApp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# how to debug properties and other things.
include(CMakePrintHelpers)
cmake_print_properties(
    TARGETS 
        theApp
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
