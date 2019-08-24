
def isDisarium(s):
	s=str(s)
	n=len(s)
	i=1
	y=0
	while i<=n:
		y+=int(s[i-1])**i
		i+=1
	if y==int(s):
		return 1
	return 0

def isArmstrong(s):
	s=str(s)
	n=len(s)
	y=0
	for i in range(n):
		y+=int(s[i])**3
		i+=1
	if y==int(s):
		return 1
	return 0

def isHappyNumber(num):
	rem=sum=0
	while num>0:
		rem=num%10
		sum+=rem**2
		num//=10
	if sum==1:
		return 1
	if sum==4:
		return 0
	return isHappyNumber(sum)

# print(isHappyNumber(int(input())))


class node:
	def __init__(self,data=None):
		self.data=data
		self.left=None
		self.right=None

def bst(root,data):
	if root==None:
		return node(data)
	if root.data>=data:
		root.left=bst(root.left,data)
	else:
		root.right=bst(root.right,data)
	return root

def inorder(root):
	if root==None:
		return 
	inorder(root.left)
	print(root.data,end=" ")
	inorder(root.right)

# n=int(input())
# li=[int(x) for x in input().split()]
# root=None
# for data in li:
# 	root=bst(root,data)

# inorder(root)
# print("")

class link:
	def __init__(self,v,w,next):
		self.v=v
		self.w=w
		self.next=next
		
n,m=[int(x) for x in input().split()]
li=[]
for i in range(n):
	li.append(None)

for i in range(m):
	u,v,w=[int(x) for x in input().split()]
	li[u]=link(v,w,li[u])

visit=[]
path=[]
for i in range(n):
	visit.append(0)
	path.append(-1)

import heapq

def dijkstra(s):
	global li
	global visit
	global path
	global n
	max=1000000
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
		temp=li[u[1]]
		while temp is not None:
			if visit[temp.v]==1:
				temp=temp.next
				continue
			heapq.heappush(heap,(u[0]+temp.w,temp.v))
			count+=1
			temp=temp.next

s,d=[int(x) for x in input().split()]
dijkstra(s)
print(path[d])

def dfs(s):
	global li
	global visit
	print(s,end=" ")
	visit[s]=1
	temp=li[s]
	while temp is not None:
		if visit[temp.v]==1:
			temp=temp.next
			continue
		dfs(temp.v)
		temp=temp.next

class queue:
	def __init__(self):
		self.q=list()
		self.n=-1

	def add(self,data):
		self.q.insert(0,data)
		self.n+=1

	def rem(self):
		self.q.pop()
		self.n-=1

	def isEmpty(self):
		if self.n==-1:
			return 1
		return 0

	def top(self):
		return self.q[self.n]

import queue

def bfs(s):
	global li
	global visit
	global n
	q=queue.Queue(maxsize=n)
	q.put(s)
	visit[s]=1
	while not q.empty():
		u=q.get()
		print(u,end=" ")
		temp=li[u]
		while temp is not None:
			if visit[temp.v]==1:
				temp=temp.next
				continue
			visit[temp.v]=1
			q.put(temp.v)
			temp=temp.next
	print("")