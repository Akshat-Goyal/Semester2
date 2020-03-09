#!/bin/bash

if (( $# != 2 ))
then
  echo "please give two arguments:the string to look up for, and the URL of the website you want to look at"
else
  wget -q -c $2 -O temp.txt
  if [[ $? -eq 0 ]] 
  then
   echo -n "$1: "
   cat temp.txt | tr -d '\n' | tr -d '\r' > temp2.txt
   mv temp2.txt temp.txt
   sed -i -r "s|<head( [^>]*)?>[^<]*</head>| |g" ./temp.txt
   sed -i -r "s|<style[^>]*>[^<]*</style>| |g" ./temp.txt
   sed -i -r "s|<script[^>]*>[^<]*</script>| |g" ./temp.txt
   sed -i -r "s|<[^>]+>| |g" ./temp.txt
   sed -i -r "s|^ *$| |g" ./temp.txt
   echo `cat temp.txt | grep -i -w -o  "$1" | wc -w`
   rm temp.txt
  else
    echo invalid url
  fi
fi


