#!/bin/bash

if (( "$#" == 2 ))
then
  echo "scale=6;$1*$2" | bc
else
  echo "wrong input is given" >&2
fi
