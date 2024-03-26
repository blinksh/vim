#! /bin/sh

# vim is in an "in-between" state: it depends on Python and TeX frameworks, which have not yet moved to XCframeworks. For the time being, we assume the frameworks are already in the right place. Later, we'll put in place automatic downloading.

# configure and make assume all Frameworks are in ./Frameworks so we move things in place:
OSX_SDKROOT=$(xcrun --sdk macosx --show-sdk-path)
IOS_SDKROOT=$(xcrun --sdk iphoneos --show-sdk-path)
SIM_SDKROOT=$(xcrun --sdk iphonesimulator --show-sdk-path)

echo "Building for iOS:"
FRAMEWORKS=$PWD/Frameworks_iOS
# rm Frameworks
# ln -s Frameworks Frameworks_iOS

make distclean
# 1) configure
# --enable-terminal
./configure vim_cv_toupper_broken=no vim_cv_terminfo=no vim_cv_tgetent=zero vim_cv_memmove_handles_overlap=no vim_cv_memcpy_handles_overlap=no vim_cv_bcopy_handles_overlap=no vim_cv_tty_group=world vim_cv_stat_ignores_slash=yes vim_cv_getcwd_broken=no --with-tlib=ncurses --with-features=normal --disable-gui --without-x --disable-netbeans --disable-channel --disable-terminal CC=clang CXX=clang++ CFLAGS="-DEXITFREE -arch arm64 -O2 -miphoneos-version-min=14.0 -isysroot $IOS_SDKROOT " CPPFLAGS="-DEXITFREE -arch arm64 -O2 -miphoneos-version-min=14.0 -isysroot $IOS_SDKROOT" CXXFLAGS="-DEXITFREE -arch arm64 -O2 -miphoneos-version-min=14.0 -isysroot $IOS_SDKROOT " LDFLAGS="-shared -arch arm64 -O2 -miphoneos-version-min=14.0 -isysroot $IOS_SDKROOT -F$FRAMEWORKS -framework ios_system " --host=armv64-apple-darwin
# --host=x86_64-apple-darwin

# 2) make. This creates ./src/vim, a Mach-O 64-bit dynamically linked shared library for arm64.
make

# 3)
echo "Creating: Frameworks/vim.framework"
framework=vim
libraryFile=src/vim
rm -rf $FRAMEWORKS/$framework.framework
mkdir -p $FRAMEWORKS/$framework.framework
cp $libraryFile $FRAMEWORKS/$framework.framework/$framework
cp basic_Info.plist $FRAMEWORKS/$framework.framework/Info.plist
plutil -replace CFBundleExecutable -string $framework $FRAMEWORKS/$framework.framework/Info.plist
plutil -replace CFBundleName -string $framework $FRAMEWORKS/$framework.framework/Info.plist
# underscore is not allowed in CFBundleIdentifier:
signature=${framework//_/-}
plutil -replace CFBundleIdentifier -string Nicolas-Holzschuch.$signature  $FRAMEWORKS/$framework.framework/Info.plist
install_name_tool -id @rpath/$framework.framework/$framework  $FRAMEWORKS/$framework.framework/$framework

echo "Creating: Frameworks/xxd.framework"
framework=xxd
libraryFile=src/xxd/xxd
rm -rf $FRAMEWORKS/$framework.framework
mkdir -p $FRAMEWORKS/$framework.framework
cp $libraryFile $FRAMEWORKS/$framework.framework/$framework
cp basic_Info.plist $FRAMEWORKS/$framework.framework/Info.plist
plutil -replace CFBundleExecutable -string $framework $FRAMEWORKS/$framework.framework/Info.plist
plutil -replace CFBundleName -string $framework $FRAMEWORKS/$framework.framework/Info.plist
# underscore is not allowed in CFBundleIdentifier:
signature=${framework//_/-}
plutil -replace CFBundleIdentifier -string Nicolas-Holzschuch.$signature  $FRAMEWORKS/$framework.framework/Info.plist
install_name_tool -id @rpath/$framework.framework/$framework  $FRAMEWORKS/$framework.framework/$framework


echo "Building for Simulator:"
FRAMEWORKS=$PWD/Frameworks_Simulator
# rm Frameworks
# ln -s Frameworks Frameworks_Simulator

make distclean
./configure vim_cv_toupper_broken=no vim_cv_terminfo=no vim_cv_tgetent=zero vim_cv_memmove_handles_overlap=no vim_cv_memcpy_handles_overlap=no vim_cv_bcopy_handles_overlap=no vim_cv_tty_group=world vim_cv_stat_ignores_slash=yes vim_cv_getcwd_broken=no --with-tlib=ncurses --with-features=normal --disable-gui --without-x --disable-netbeans --disable-channel --disable-terminal CC=clang CXX=clang++ CFLAGS="-DEXITFREE -arch x86_64 -O2 -miphoneos-version-min=14.0 -isysroot $SIM_SDKROOT " CPPFLAGS="-DEXITFREE -arch x86_64 -O2 -miphoneos-version-min=14.0 -isysroot $SIM_SDKROOT" CXXFLAGS="-DEXITFREE -arch x86_64 -O2 -miphoneos-version-min=14.0 -isysroot $SIM_SDKROOT " LDFLAGS="-shared -arch x86_64 -O2 -miphoneos-version-min=14.0 -isysroot $SIM_SDKROOT -F$FRAMEWORKS -framework ios_system " --host=arm64-apple-darwin
#--host=x86_64-apple-darwin

# 2) make. This creates ./src/vim, a Mach-O 64-bit dynamically linked shared library for arm64.
make

# 3)
echo "Creating: Frameworks/vim.framework"
framework=vim
libraryFile=src/vim
rm -rf Frameworks_Simulator/$framework.framework
mkdir -p Frameworks_Simulator/$framework.framework
cp $libraryFile Frameworks_Simulator/$framework.framework/$framework
cp basic_Info_Simulator.plist Frameworks_Simulator/$framework.framework/Info.plist
plutil -replace CFBundleExecutable -string $framework Frameworks_Simulator/$framework.framework/Info.plist
plutil -replace CFBundleName -string $framework Frameworks_Simulator/$framework.framework/Info.plist
# underscore is not allowed in CFBundleIdentifier:
signature=${framework//_/-}
plutil -replace CFBundleIdentifier -string Nicolas-Holzschuch.$signature  Frameworks_Simulator/$framework.framework/Info.plist
install_name_tool -id @rpath/$framework.framework/$framework  Frameworks_Simulator/$framework.framework/$framework

echo "Creating: Frameworks/xxd.framework"
framework=xxd
libraryFile=src/xxd/xxd
rm -rf Frameworks_Simulator/$framework.framework
mkdir -p Frameworks_Simulator/$framework.framework
cp $libraryFile Frameworks_Simulator/$framework.framework/$framework
cp basic_Info_Simulator.plist Frameworks_Simulator/$framework.framework/Info.plist
plutil -replace CFBundleExecutable -string $framework Frameworks_Simulator/$framework.framework/Info.plist
plutil -replace CFBundleName -string $framework Frameworks_Simulator/$framework.framework/Info.plist
# underscore is not allowed in CFBundleIdentifier:
signature=${framework//_/-}
plutil -replace CFBundleIdentifier -string Nicolas-Holzschuch.$signature  Frameworks_Simulator/$framework.framework/Info.plist
install_name_tool -id @rpath/$framework.framework/$framework  Frameworks_Simulator/$framework.framework/$framework

# 6)
echo "Merging into xcframeworks:"

for framework in vim xxd
do
   rm -rf $framework.xcframework
   xcodebuild -create-xcframework -framework Frameworks_iOS/$framework.framework -framework Frameworks_Simulator/$framework.framework -output $framework.xcframework
   # xcodebuild -create-xcframework -framework Frameworks_iOS/$framework.framework -output $framework.xcframework
   # while we're at it, let's compute the checksum:
   rm -f $framework.xcframework.zip
   zip -rq $framework.xcframework.zip $framework.xcframework
   swift package compute-checksum $framework.xcframework.zip
done

zip -rq runtime.zip runtime/
