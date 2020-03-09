#!/bin/bash

if (( $# != 1 ))
then
  echo "give 1 argument:number of iterations (work + break)"
  exit
fi

for (( i=1;i<=$1;i++ ))
do
  notify-send "Work"
  sleep 1500

  if (( $(( i%4 )) == 0 ))
  then
    notify-send "Long Break"
    sleep 900
  else
    notify-send "Break Time"
    sleep 300
  fi
done

notify-send "Cycles Finished"

