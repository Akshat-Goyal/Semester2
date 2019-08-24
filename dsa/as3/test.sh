#!/bin/bash

i=$1
# at max 10000 iterations
if [[ $i -eq 100 ]]
then
	exit 1
fi

if [ -e "in.txt" ]
then
  rm "in.txt"
fi

/usr/bin/python3 test_tax.py > "in.txt"

# put the paths below
./t < "in.txt" > "111.txt"
./a.out < "in.txt" > "222.txt"
cmp "111.txt" "222.txt"
if (( $? == 0  ))
then
    ./test.sh $(($i + 1))
     exit $?
else
	echo wrong
	exit 0
fi
