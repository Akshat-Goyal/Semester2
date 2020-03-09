#!/bin/bash

if (( $#!=2 ))
then
	echo wrong no. of arguents.
	exit
fi

while (( 1 ))
do
	top -b -o +%MEM | head -n $(expr $1 + 7 ) | tail -"$1" | rev | cut -d" " -f1 | rev
	sleep "$2"
	echo
done
