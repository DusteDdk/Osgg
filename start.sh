#!/bin/bash
# Entirely too desperate to star the game

M=$(uname -m)
if [ "$M" == "x86_64" ]
then
    A="x64"
else
    A="x86"
fi

osggLauncher=false
if [ -f launcher_linux_$A ]
then
    echo "Found precompiled launcher"
    osggLauncher=./launcher_linux_$A
else
    if [ -f ./launcher/launcher ]
    then
        echo "Found manually compiled launcher"
        osggLauncher=./launcher/launcher
    fi
fi

if [ "$osggLauncher" != "false" ]
then

    if ! $osggLauncher
    then
        echo "The launcher did not work"
        osggLauncher=false
    fi
else
    echo "Found no launcher"
fi

if [ "$osggLauncher" == "false" ]
then
    echo "Trying to start the game directly..."
    if [ -f osgg_linux_$A ]
    then
        echo "Found precompiled osgg binary"
        ./osgg_linux_$A
    elif [ -f osgg ]
    then
        echo "Found manually compiled osgg binary"
        ./osgg
    else
        echo "Sorry, osgg has not been compiled.."
        echo "To compile it, type:"
        echo "make"
        exit 1
    fi
fi