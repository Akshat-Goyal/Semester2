#!/bin/bash

ls -lR | while read i
do  
  f=`echo $i | rev | cut -d" " -f1 | rev`
  if [[ "$i" = [.]* ]]
  then
    d=`echo $i | cut -d":" -f1`
  elif [[ -f ""$d"/"$f"" ]]
  then
    echo -e "`date -r "$d"/"$f" +"%d-%m-%y %H:%M:%S"` \c"
    echo "$d"/"$f"
  fi
done


whatis -r "^lo" > 2018101075.txt
cat 2018101075.txt | wc -lL
cp 2018101075.txt{,.bak}
sed -i 's/function/method/g' 2018101075.txt

