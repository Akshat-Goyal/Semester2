#! /bin/bash

#for i in *

ls | while read i
do
  mv "$i" "$i".lol
done
