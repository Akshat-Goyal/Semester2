#!/bin/bash

if [ ! -e reminder.csv ]
then
  echo no remainder
  exit
fi

c=`cat reminder.csv | wc -l`
c=$(( c - 1 ))
cat reminder.csv > temp.csv
cat temp.csv | head -1 > reminder.csv
cat temp.csv | tail -"$c" | while read i
do
  a=`echo $i | cut -d"," -f 1`
  b=`at -l | cut -f 1 | grep -c "$a"`
  if (( $b != 0 ))
  then
    echo $i >> reminder.csv
  fi
done

if (( $# == 0 ))
then
  cat reminder.csv | column -t -s ","
elif (( $# == 1 ))
then
  head -1 reminder.csv > temp.csv
  a=`echo $1 | cut -d":" -f1`
  b=`echo $1 | cut -d":" -f2`
  if [[ "$a" = "date" ]]
  then
    awk -F"," -v name="$b" '{
         if($2 == name)
           printf("%s\n",$0);
    }' reminder.csv >> temp.csv
    cat temp.csv | column -t -s ","
    rm temp.csv
  else
    awk -F"," -v name="$b" '$4 ~ name {
           print $0
    }' reminder.csv >> temp.csv
    cat temp.csv | column -t -s ","
    rm temp.csv
  fi
else
  echo wrong arguments
fi
