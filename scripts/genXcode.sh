#!/bin/sh

# Generate an Xcode project

# -B <path-to-build> = Explicitly specify a build directory.
cmake -G Xcode -H.. -B../buildMacOS -D USE_UNIT_TESTING=ON -D GENERATE_DOC=ON
