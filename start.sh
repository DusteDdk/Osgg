#!/bin/bash
if ! ./launcher/launcher
then
  echo "The launcher did not work.."
  ./osgg
fi

