#!/bin/bash
cd launcher
if ! ./launcher
then
  cd ..
  echo "The launcher did not work.."
  ./osgg
fi

