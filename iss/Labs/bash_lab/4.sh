#! /bin/bash

n=$#

ar=("$@")

function swap(){
  t=${ar[$j]}
  ar[$j]=${ar[$(( j+1 ))]}
  ar[$(( j+1 ))]=$t
}

for (( i=0;i<$(expr $n-1 ) ;i++ ))
do
  for(( j=0;j<$(expr $n-1-$i );j++ ))
  do
    if (( ${ar[$j]} > ${ar[$(( j+1 ))]} ))
    then
     swap 
    fi
  done
done 

for (( i=0;i<$n;i++ ))
do
  echo -e "${ar[$i]} \c"
done
echo -e "\n\c"
