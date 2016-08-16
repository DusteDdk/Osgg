#!/bin/bash
# This file is executed by contigratord when a build is triggered.
# You can execute it manually too by executing /home/contigrator/contigrator/tool/trigBuild.sh

#These variables are available:
# $WD = The workspace $BN = Zero padded build Number (%07i) and $BN_NUM for unpadded.
# $OUT = This empty directory is created for you to store the output of the build.
set -e;set -x

#Add your build instructions below:

echo "Osgg build script."

rm -Rf Osgg-version*
# Ouch, extract version from source code...
VER=$(cat main.cpp | grep "define VERSION" | cut -f 2 -d '"')
DST="$JOBNAME"-version_$VER"-build_$BN"
mkdir $DST

echo =
echo == Building 64 bit linux version ...
echo ===

# 64 bit version
pushd launcher
qmake DEFINES+='EXECPATH=\"\\\"./osgg_linux_x64\\\"\"'
make clean
make
popd
make clean
make

mv launcher/launcher $DST/launcher_linux_x64
mv osgg $DST/osgg_linux_x64

# Clean
make clean
pushd launcher
make clean
popd

echo =
echo == Building 32 bit linux version ...
echo ===


# The chrooted 32 bit linux version.
sudo -E -P USER=$USER USERNAME=$USER LOGNAME=$LOGNAME -- /usr/sbin/chroot /var/local/32bitDeb/ su -p -l $USER -c "cd /home/contigrator/jobs/Osgg/workspace/launcher && qmake DEFINES+='EXECPATH=\"\\\"./osgg_linux_x86\\\"\"' && make && cd .. && make "

mv launcher/launcher $DST/launcher_linux_x86
mv osgg $DST/osgg_linux_x86

echo =
echo == Building 32 bit windows version ...
echo ===

# The windows version
pushd launcher
OLDPATH="$PATH"
PATH="/home/contigrator/mxe/usr/bin:$PATH"
echo "Current path: $PATH"
i686-w64-mingw32.static-qmake-qt4 DEFINES+='EXECPATH=\"\\\"osgg_windows.exe\\\"\"'
make
PATH="$OLDPATH"
unset OLDPATH
find .
mv "./release/launcher.exe" "../$DST/launcher_windows.exe"
rm -Rf debug
rm -Rf release
rm -f *.o
rm -f *.exe
popd
make clean
make -f Makefile.win
mv osgg.exe $DST/osgg_windows.exe

echo =
echo == Packaging ...
echo ===



# Data files
cp -r demos levels *.txt *.ttf *.txt *.ogg *.png *.sh $DST
cp -r ../dlls/* $DST

tar jcf "$DST".tar.bz2 $DST

zip -r "$DST".zip $DST

mv "$DST".tar.bz2 $OUT
mv "$DST".zip $OUT

rm -R "$DST"

