#ifndef GEND_ACCOUNTLIB_H
#define GEND_ACCOUNTLIB_H

#pragma once

#include <string>

//#include "gend/Account.hpp"

/**
    @mainpage accountLib - A library for nothing really.
    @anchor mainpage
    @brief __accountLib__ is a cross-platform C++ library for nothing.

    The following frobs are currently implemented:
    - Account
    
    @par Contact
    Gene De Lisa: <gene@rockhoppertech.com>
    
    @author
    This code has been authored by <a href="http://rockhoppertech.com">Gene De Lisa</a>

    @copyright
    Copyright (C) 2019 Rockhopper Technologies, Inc.
    
    @par Licence
    This project is released under the <a href="https://opensource.org/licenses/MIT">MIT</a> license.
    @n@n
    Copyright 2019 Rockhopper Technologies, Inc.

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
    
    @par Dependencies & Compatibiliy
    The library uses c++17.
    It depends on 
    - <a href="https://github.com/google/googletest">Google Test</a> for unit-testing.
    
    @section download Download
    
    The source code is available on __Github__: https://github.com/genedelisa/cppGoogleTestDLProject
 
    @section toc Table of Contents
 
    1. @subpage Compilation @n
    3. @subpage Examples @n
 
    @page Compilation
    @section compile-lib Compiling the library
    @tableofcontents

    @subsection dependencies Dependencies

    To compile the library, you should install the following dependencies:
    - Boost: <a href="http://www.boost.org/">http://www.boost.org/</a>

    Google Test is downloaded via Cmake. Boost is far too large to do this.

    @subsection compiling Compiling as a static/dynamic library
    @par XCode

    See the xcode project in "ide/xcode/"

    @par CMake

    The library can be built using <a href="http://www.cmake.org/">CMake</a>.
    In the root directory, type the following command to generate the Makefiles:
    ```
    cmake . -G"Unix Makefiles"
    ```
    The following commands can be used to build the static library and run the unit tests, and generate the documentation:
    ```
    make
    make tests
    ```

    The following commands can be used to generate the developer documentation and the api documentation:
    ```
    make doc
    ```
    @par Usage

    The header file "accountLib.h" includes the public headers of the library.


 
    <center>Prev: @ref mainpage "Home" | Next: @ref Examples "Examples".</center>
 
    @page Examples

    @section cppex C++ Example

    @code{.cpp}
    #include <gend/accountLib.h>

    int main() {
        Account account;
        return EXIT_SUCCESS;

    }
    @endcode

    
    <center>Prev: \ref Compilation | Up: \ref mainpage "Home".</center>
 */


/**
 * @brief A namespace containing Gene's frobs.
 *
 * Right now it contains just Account.
 *
 * @author Gene De Lisa <gene@rockhoppertech.com>
 */
namespace gend {
}


#endif
