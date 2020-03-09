#!/bin/bash

if (( $# != 1 ))
then
  echo "give 1 argument:number of iterations (work + break)"
  exit
fi

for (( i=1;i<=$1;i++ ))
do
  echo "Work"
  sleep 1500

  if (( $(( i%4 )) == 0 ))
  then
    echo "Long Break"
    sleep 900
  else
    echo "Break Time"
    sleep 300
  fi
done

echo "Cycles Finished"

