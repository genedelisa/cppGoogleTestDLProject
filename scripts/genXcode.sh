#!/bin/sh

# Generate an Xcode project

# -B <path-to-build> = Explicitly specify a build directory.
cmake -G Xcode -H.. -B../buildMacOS
