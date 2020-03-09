#!/bin/bash


find "$1" -type f-+ -printf "%b %p\n" | sort -n | tail -1 | cut -d" " -f2
# du -a "$1" | sort -nr | head -1 | cut -f2
