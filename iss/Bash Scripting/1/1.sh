#!/bin/bash

if [ ! -e music.csv ]
  then
    touch music.csv
    echo id,song_name > music.csv
  fi

if [[ "$1" = "add" ]]
then
    a=`cat music.csv | tail -1 | cut -d"," -f1 | bc -l`
    if [[ "$a" = "" ]]
    then
        id=1
    else
        id=$(echo "$a + 1" | bc -l)
    fi

    ar=('')
    n=0
    ar[0]=$id

    f=0
    for (( i=2;i<=$#;i++ ))
    do
       x=`echo "${!i}" | cut -d":" -f1`
       if [[ "$x" = "song_name" ]]
       then
           f=1
           a=`echo ${!i} | cut -d":" -f2`
           b=`cat music.csv | cut -d"," -f 2 | grep -w "^$a$" | wc -l`
           if (( $b != 0 ))
           then
               echo song name already exists
               exit
           fi
       fi
       y=`cat music.csv | head -1 | grep "$x" | wc -l`
       if (( $y == 0 ))
       then
           q=`cat music.csv | head -1`
	   sed -i '1,1d' music.csv
	   sed -i "1 s/^/""$q","$x""\n/" music.csv
       fi
       z=`awk -v name="$x" -F',' '
       {
          for(i=1;i<=NF;i++) {
              if($i == name)
              printf("%d",i-1)
          } 
          exit 0
       }
      ' music.csv`
      if (( $n < $z ))
      then
          n=$z
      fi
      ar[$z]=`echo ${!i} | cut -d":" -f2` 
   done

   if [[ $f == 0 ]]
   then
       echo song name is not given
       exit
   fi
 
   echo `for (( i=0;i<$n;i++ ))
   do
     echo -e "${ar[$i]},\c"
     done`${ar[$n]} >> music.csv
   sed -i "s/,,/, ,/g" music.csv 


elif [[ "$1" = "delete" ]]
then
    sed -i "/^$2\b/d" ./music.csv


elif [[ "$1" = "edit" ]]
then
    head -1 music.csv > temp.csv
    cat music.csv | grep "^$2" >> temp.csv
    a=`cat music.csv | tail -1 | cut -d"," -f1 | bc -l`

    if [[ "$a" = "" ]]
    then
        id=1
    else
        id=$(echo "$a + 1" | bc -l)
    fi

    n=`tail -1 temp.csv | grep -o "," | wc -l`
    ar=('')
    ar[0]=$id

    for (( i=1; i<=$n; i++ ))
    do
        j=$(expr $i + 1 )
        ar[$i]=`tail -1 temp.csv | cut -d"," -f"$j"`
    done

    for (( i=3;i<=$#;i++ ))
    do
       x=`echo "${!i}" | cut -d":" -f1`
       if [[ "$x" = "song_name" ]]
       then
           a=`echo ${!i} | cut -d":" -f2`
           b=`cat music.csv | cut -d"," -f 2 | grep -w "^$a$" | wc -l`
           if (( $b != 0 ))
           then
               echo song name already exists
               exit
           fi
       fi

       y=`head -1 temp.csv | grep "$x" | wc -l`
       if (( $y == 0 ))
       then
           q=`head -1 temp.csv`
	   sed -i '1,1d' music.csv
           sed -i "1 s/^/""$q","$x""\n/" music.csv
	   sed -i '1,1d' temp.csv
           sed -i "1 s/^/""$q","$x""\n/" temp.csv
       fi

       z=`awk -v name="$x" -F',' '
       { 
          for(i=1;i<=NF;i++) {
              if($i == name)
              printf("%d",i-1)
          } 
          exit 0
       }
       ' temp.csv`

       if (( $n < $z ))
       then
           n=$z
       fi

       ar[$z]=`echo ${!i} | cut -d":" -f2`
    done

    ./1.sh "delete" "$2"
    echo `for (( i=0;i<$n;i++ ))
    do 
        echo -e "${ar[$i]},\c"
    done `${ar[$n]} >> music.csv
    rm temp.csv


elif [[ "$1" = "list" ]]
then
    if [ -e music.csv ]
    then
        cat music.csv | column -t -s","
    else
        echo song file empty
    fi


elif [[ "$1" = "select" ]]
then
    if [ ! -e music.csv ]
    then
        echo song file is empty
        exit
    fi

    cat music.csv > temp0.csv
    for (( i=2;i<=$#;i++ ))
    do
        x=`echo "${!i}" | cut -d":" -f1`

        z=`awk -v name="$x" -F',' '
        {
            for(i=1;i<=NF;i++) {
                if($i == name)
                printf("%d",i-1)
            } 
            exit 0
       }
       ' music.csv`

       if [[ "$z" = "" ]]
       then
           echo this field does not exist
           exit
       fi

       y=`echo "${!i}" | cut -d":" -f2`

       z=$(( z + 1 ))
       awk -F"," -v name="$y" -v var="$z" '{ if ($var == name) print}' temp0.csv > temp1.csv
       sed -i "1 s/^/`head -1 music.csv`\n/" temp1.csv
       mv temp1.csv temp0.csv
   done
   cat temp0.csv | column -t -s ","
   rm temp0.csv 


else
  echo wrong command given
fi




#sed -n -i "p;1a ""$q","$x""" music.csv
#sed -i '1,1d' music.csv
