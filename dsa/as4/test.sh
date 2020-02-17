#!/bin/bash

i=$1

if [[ $i -eq 100 ]]
then
	exit 1
fi

# if [ -e "in.txt" ]
# then
#   rm "in.txt"
# fi

node test.js > "in.txt"

# put the paths below
./mk < "in.txt" > "11.txt"
./mn < "in.txt" > "22.txt"
cmp "11.txt" "22.txt"
if (( $? == 0  ))
then
    ./test.sh $(($i + 1))
else
	echo wrong
  echo manish
  cat 22.txt
  echo ""
  echo mayank
  cat 11.txt
	exit 0
fi
