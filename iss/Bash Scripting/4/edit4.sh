#!/bin/bash

if (( $# < 4 )) || (( $# > 5 ))
then
  echo give arguments for "id,date(YY-MM-DD),time(hr:min),body,frequency(optional)"
fi

./delete4.sh $1
if (( $# == 4 ))
then
  ./add4.sh $2 $3 $4
else
  ./add4.sh $2 $3 $4 $5
fi
