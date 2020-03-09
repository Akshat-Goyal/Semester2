#! /bin/bash

for (( i=0,j=1; j<1000 ;  ))
do
  echo -e "$j \c"
  t=$(( i+j ))
  i=$j
  j=$t
done
echo -e "\n\c"
