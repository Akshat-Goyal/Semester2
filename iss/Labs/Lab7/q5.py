#!/usr/bin/python3

import sys
import re

s=str(open(sys.argv[1]).read())

pat=['[^!.?,:;"()]+']
for r in pat:
	s=re.findall(r,s)

s="".join(s).split(" ")

set1={}
for i in s:
	set1[i]=set1[i]+1 if set1.get(i) else 1

f=open(sys.argv[2], "w")

for i in s:
	if set1[i]>0:
		f.write(i+": "+str(set1[i])+"\n")
		set1[i]=0
