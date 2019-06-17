# Gene's C++ frobs

[![GitHub last commit](https://img.shields.io/github/last-commit/genedelisa/vscode-cppprojects.svg)](https://github.com/genedelisa/vscode-cppprojects/commits/master)

[![GitHub release](https://img.shields.io/github/release/genedelisa/vscode-cppprojects.svg)](https://github.com/genedelisa/vscode-cppprojects/releases/)
[![GitHub release date](https://img.shields.io/github/release-date/genedelisa/vscode-cppprojects.svg)](https://github.com/genedelisa/vscode-cppprojects/releases)


[![C++17](https://img.shields.io/badge/c++17-compatible-4BC51D.svg?style=flat")](https://www.iso.org/standard/68564.html)
[![Platforms macOS](https://img.shields.io/badge/Platforms-OS%20X-lightgray.svg?style=flat)](https://swift.org/)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://en.wikipedia.org/wiki/MIT_License)

[![Sponsors](https://img.shields.io/badge/Sponsors-Rockhopper%20Technologies-orange.svg?style=flat)](http://www.rockhoppertech.com/)
[![Twitter @GeneDeLisaDev](https://img.shields.io/twitter/follow/GeneDeLisaDev.svg?style=social)](https://twitter.com/GeneDeLisaDev)
![GitHub followers](https://img.shields.io/github/followers/genedelisa.svg?label=Follow&style=social)

## What's this?

Running NodeJS/{Java,Type}Script in vscode? Easy. 
C++? Not so much.

This is a Visual Studio Code multi-root workspace containing separate small C++ projects. helloworld and helloworld2 have the same contents. I wanted to see if the tasks would work for each project. Yes! The task picker will tell you which project your are currently in.


You **should** be able to simply copy the helloworld project, add the copy to the workspace, then replace the code with your own.

The executable generated will be named the same as your project name.

You can build via cmake/make, or use the active file task if you're compiling just one file.

I'm not a visual studio code expert. But out of the box, developing C++ is a bit of a pain.
If you know an easier way, let me know!

## Tasks defined

### cmake and make
Runs cmake to create the Makefile in build, then it runs make to build the executable.

### make
You probably want to run cmake once. Then when your code is updated, run make.

### clang++ C++17 build active file
If you are editing a C++ file and you want to compile it, choose this task.

If you are editing a non C++ file and run this, hilarity will ensue.

### clean
Removes the contents of the build directory.


## Blog post for this example.

[Blog post coming coon](http://www.rockhoppertech.com/blog/)


### Buy my kitty Giacomo some cat food
If you find this useful, my kitty likes snacks.

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=F5KE9Z29MH8YQ&bnP-DonationsBF:btn_donate_SM.gif:NonHosted)

<img src="http://www.rockhoppertech.com/blog/wp-content/uploads/2016/07/momocoding-1024.png" alt="Giacomo Kitty" width="400" height="300">


## Licensing

[MIT](https://en.wikipedia.org/wiki/MIT_License)

Please read the [LICENSE](LICENSE) for details.

## Credits

*	[Gene De Lisa's development blog](http://rockhoppertech.com/blog/)
*	[Gene De Lisa's music blog](http://genedelisa.com/)
*   Twitter: [@GeneDeLisaDev](http://twitter.com/genedelisadev)
