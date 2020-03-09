#!/bin/bash

############  if no argument is given it will start recording session  ############
#####  if session no. as argument is given then it will replay that session  ######

if [ ! -d ~/.dump ]
then
    mkdir ~/.dump
fi

runScript () {
    if [ -f "$1" ]
    then
        scriptreplay --timing=file_time "$1"
    else
        echo file does not exist
    fi
}

if (( $# == 0 ))
then
    a=`ls -1 ~/.dump/ | sort | tail -1`
    if [[ "$a" = "" ]]
    then 
        script --timing=file_time ~/.dump/1
    else
        let a++
        script --timing=file_time ~/.dump/"$a"
    fi
else
    runScript ~/.dump/"$1"  
fi
