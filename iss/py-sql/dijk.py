from sys import stdin, stdout

import collections

T=int(stdin.readline())
while T>0:

	n,m=[int(x) for x in stdin.readline().split()]
	li=[]
	for i in range(n):
		li.append(collections.deque())

	for i in range(m):
		u,v,w=[int(x) for x in stdin.readline().split()]
		li[u-1].append((v-1,w))

	visit=[]
	path=[]
	for i in range(n):
		visit.append(0)
		path.append(-1)

	import heapq

	max=100000010
	def dijkstra(s):
		global li
		global visit
		global path
		global n
		global max
		heap=[(0,s)]
		count=1
		for i in range(n):
			heap.append((max,i))
			count+=1
		heapq.heapify(heap)
		while count>0:
			u=heapq.heappop(heap)
			count-=1
			if visit[u[1]]==1:
				continue
			path[u[1]]=u[0]
			visit[u[1]]=1
			for temp in li[u[1]]:
				if visit[temp[0]]==1:
					continue
				heapq.heappush(heap,(u[0]+temp[1],temp[0]))
				count+=1

	s,d=[int(x)-1 for x in stdin.readline().split()]
	dijkstra(s)
	if path[d]==max:
		stdout.write("NO\n")
	else:
		stdout.write(str(path[d])+"\n")
	T-=1
