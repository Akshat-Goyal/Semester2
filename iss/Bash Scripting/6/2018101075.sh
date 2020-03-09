#!/bin/bash

if (( $# != 2 ))
then
  echo "give two commands:<movies_rating_file_path> <all_movies_folder_path>"
  exit
fi

mkdir "$2"Bad "$2"Average "$2"Good "$2"Awesome 2>/dev/null

cat "$1" | while read p
do
  a=`echo $p | cut -d":" -f2 | bc`
  b=`echo $p | cut -d":" -f1`
  if (( $(echo "$a < 5" | bc -l ) ))
  then 
    touch "$2"Bad/"$b".mp4
  elif (( $(echo "$a >= 5" | bc -l ) )) && (( $(echo "$a < 8" | bc -l ) ))
  then
    touch "$2"Average/"$b".mp4
  elif (( $(echo "$a >= 8" | bc -l ) )) && (( $(echo "$a < 9" | bc -l ) ))
  then
    touch "$2"Good/"$b".mp4
  else
    touch "$2"Awesome/"$b".mp4
  fi
done
