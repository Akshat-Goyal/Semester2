#!/bin/bash

########  format of date YYYY-MM-DD #########
########  archive folder will be formed in the directory in which given folder lies. ########
 
d1=`date +%Y-%m-%d`
d1=`date +%s -d "$d1"`
d2=`date +%s -d "$2"`
((diff_sec=d2-d1))
a=`echo - | awk -v SECS=$diff_sec '{printf "%d",SECS/(60*60*24)}'`
let "a=-$a"
mkdir "$1"/../archive-"$2" 2> /dev/null 
find "$1" -type f -mtime +"$a" -exec mv "{}" "$1"/../archive-"$2"/ \;
