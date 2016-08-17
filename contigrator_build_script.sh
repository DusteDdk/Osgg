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

# =
# == Building 64 bit linux version ...
# ===

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

# =
# == Building 32 bit linux version ...
# ===

TMPSCRIPT=`mktemp`
if [ -f $TMPSCRIPT ]
then
  # I seriously can't figure out a sane way of getting the literal string: qmake DEFINES+='EXECPATH=\"\\\"./osgg_linux_x64\\\"\"' executed in the chrooted environment in a different way.. except for committing the file, and that's also ugly..
  echo IyEvYmluL2Jhc2gKY2QgL2hvbWUvY29udGlncmF0b3Ivam9icy9Pc2dnL3dvcmtzcGFjZS9sYXVuY2hlcgpxbWFrZSBERUZJTkVTKz0nRVhFQ1BBVEg9XCJcXFwiLi9vc2dnX2xpbnV4X3g4NlxcXCJcIicKbWFrZQpjZCAuLgptYWtlCg== | base64 -d > $TMPSCRIPT
  chmod +x $TMPSCRIPT

# The chrooted 32 bit linux version.
  sudo -E -P USER=$USER USERNAME=$USER LOGNAME=$LOGNAME -- /usr/sbin/chroot /var/local/32bitDeb/ su -p -l $USER -c "$TMPSCRIPT"
  rm -f $TMPSCRIPT

  mv launcher/launcher $DST/launcher_linux_x86
  mv osgg $DST/osgg_linux_x86
fi

# =
# == Building 32 bit windows version ...
# ===

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
mv "./release/launcher.exe" "../launcher.exe"
rm -Rf debug
rm -Rf release
rm -f *.o
rm -f *.exe
popd
make clean
make -f Makefile.win

# =
# == Packaging ...
# ===

# Add changelog
git log > changelog.txt
cp changelog.txt $DST/changelog.txt

# Data files
cp -r demos levels *.txt *.ttf *.txt *.ogg *.png start.sh $DST

#Package the Linux version
tar -c $DST | pbzip2 > "$DST"_linux.tar.bz2

# Remove linux binaries for the zip
rm $DST/*_linux_*
rm $DST/*.sh
# Add .exe files for the windows version
mv launcher.exe $DST/launcher_windows.exe
mv osgg.exe $DST/osgg_windows.exe
unix2dos $DST/changelog.txt
# Add dlls for the windows version
cp -r ../dlls/* $DST
# Add .bat for the windows version
cp start.bat $DST
zip -r "$DST"_windows.zip $DST

mv "$DST"_linux.tar.bz2 $OUT
mv "$DST"_windows.zip $OUT

rm -R "$DST"

# Build the source code
git archive --prefix="osgg_build_$BN"_src/ HEAD > "$DST"_src.tar
tar --file "$DST"_src.tar --append --transform 's%^%osgg_build_'$BN'_src/%' changelog.txt
cat "$DST"_src.tar | pxz > "$OUT/$DST"_src.tar.xz

rm -f "$DST"_src.tar changelog.txt
