#!/bin/bash

name="window"
for (( i=1;;i++ ))
do
    a=`tmux ls | cut -d":" -f1 | grep ""$name""$i"" | wc -l` 
    if (( $a == 0 ))
    then
        name=""$name""$i""
        tmux new -d -s "$name" 
        break
    fi
done

tmux send-keys "htop" C-m 
tmux splitw -v
tmux send-keys "sudo tcpdump 'port 443' and 'port 80'" C-m
tmux selectp -t 0
tmux splitw -h
tmux send-keys "watch -n 1 date" C-m 
tmux attach-session -t "$name" 
