#!/bin/bash

mkdir -p "${BASH_SOURCE%/*}/Frameworks"

(cd "${BASH_SOURCE%/*}/Frameworks"
# ios_system - Blink only depends on ios_system, as it doesn't include lua or python, etc...
echo "Downloading Frameworks:"
curl -OL https://github.com/holzschu/ios_system/releases/download/v3.0.3/ios_system.xcframework.zip
sha=$( shasum -a 256 ios_system.xcframework.zip | cut -d' ' -f1 )
[[ "$sha" == "50f1692873e73fd862f45f73f2c08745e822c01ff5e0a0e0aec7fed6bb946e7f" ]] && echo "sha matches" || exit 1
unzip ios_system.xcframework.zip && rm ios_system.xcframework.zip
)

# Commented. Made part of the repo to simplify Blink customization
# (cd "${BASH_SOURCE%/*}/src/"
# # ios_error.h
# curl -OL $HHROOT/ios_system/releases/download/v$IOS_SYSTEM_VER/ios_error.h
# )
