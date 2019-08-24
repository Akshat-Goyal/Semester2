#!/bin/bash

i=$1

if [[ $i -eq 100 ]]
then
	exit 1
fi

if [ -e "in.txt" ]
then
  rm "in.txt"
fi

node test_good.js > "in.txt"

# put the paths below
./g < "in.txt" > "11.txt"
./a.out < "in.txt" > "22.txt"
cmp "11.txt" "22.txt"
if (( $? == 0  ))
then
    ./test.sh $(($i + 1))
     exit $?
else
	echo wrong
	exit 0
fi
