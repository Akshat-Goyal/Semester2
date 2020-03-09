#!/bin/bash


if [ ! -e reminder.csv ]
then
  touch reminder.csv
  echo "id,date(YY-MM-DD),time(hr:min),body"> reminder.csv
fi

if (( $# <3 )) || (( $# > 4 ))
then
   echo invalid arguents
   echo "give arguments for date,time, body, frequency(optional)"
   echo "format of date: YY-MM-DD time: h:min(in 24h) and date & time shouldn't be of past"
   exit
fi

if [[ "$4" = "" ]]
then 
  n=1
else
  n=$4
fi

a=$1
b=$2
f=0
   
for (( i=1;i<=$n;i++ ))
do
  if (( $f == 1 ))
  then
    a=`date +%y-%m-%d -d "$a+7 days"`
  else
    f=1
  fi
  echo "notify-send $3" | at "$b $a" 2>temp.txt
  if (( $? != 0 ))
  then
    echo invalid date
    echo "give arguments for date,time, body, frequency(optional)"
    echo "format of date: YY-MM-DD time: h:min(in 24h) and date & time shouldn't be of past"
    exit
  fi
  c=`cat temp.txt | tail -1 | cut -d" " -f 2`
  rm temp.txt 
  sed -i "/^"$c",/d" ./reminder.csv
  echo $c,$a,$b,$3 >> reminder.csv
  c=`cat reminder.csv | wc -l`
  c=$(( c-1 ))
  cat reminder.csv | tail -"$c" > temp.csv
  echo "id,date(YY-MM-DD),time(hr:min),body" > reminder.csv
  sort -k 1 -k 2 -k 3 < temp.csv | cat >> reminder.csv
  rm temp.csv
done
