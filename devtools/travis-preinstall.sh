#!/usr/bin/env bash

# This script downloads, builds, and installs the SteamVR-OSVR dependencies
# It's designed to be used primarily by Travis CI in conjunction with the
# .travis.yml script.

set -ev

# Download dependencies
if [ $TRAVIS_OS_NAME = 'linux' ]; then
    export INSTPRF=$HOME/p
    mkdir -p $INSTPRF

    pushd $HOME
    git clone https://github.com/open-source-parsers/jsoncpp.git
    git clone https://github.com/OSVR/libfunctionality.git
    git clone https://github.com/OSVR/OSVR-Core.git
    popd
fi

if [ $TRAVIS_OS_NAME = 'osx' ]; then
    brew update
    brew tap homebrew/science
    brew tap d235j/osvr
fi

