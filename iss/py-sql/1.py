# 1.
x = str(input())

i=0
j=len(x)-1

while i<j:
	if x[i]!=x[j]:
		print("not a palindrome")
		exit()
	i+=1
	j-=1

print("palindrome")

# 2.
from sys import stdin, stdout

def scan(n,m):
	mat=[]
	for i in range(n):
		mat.append([])
		for x in stdin.readline().split():
			mat[i].append(int(x))

	return mat

def identity():
	n=int(stdin.readline())
	for i in range(n):
		for j in range(n):
			if i==j:
				stdout.write("1 ")
			else:
				stdout.write("0 ")
		stdout.write("\n")

def add(mat1,mat2,n,m):
	for i in range(n):
		for j in range(m):
			stdout.write(str(mat1[i][j]+mat2[i][j])+" ")
		stdout.write("\n")

def transpose(mat,n,m):
	for j in range(m):
		for i in range(n):
			stdout.write(str(mat[i][j])+" ")
		stdout.write("\n")	

def multiply(mat,mat1,n,m,n1):
	for i in range(n):
		for j in range(0,n1):
			y=0
			for k in range(m):
				y+=mat[i][k]*mat1[k][j]
			stdout.write(str(y)+" ")
		stdout.write("\n")

# n,m = [int(x) for x in stdin.readline().split()]
# mat=scan(n,m)

# n1,m1 = [int(x) for x in stdin.readline().split()]
# mat1=scan(n1,m1)

# identity()
# add(mat,mat1,n,m)
# transpose(mat,n,m)
# multiply(mat,mat1,n,m,m1)

# 3.
n=int(input())
m=n

for i in range(n):
	for i in range(n-m):
		print(" ",end="")
	for i in range(m):
		print("*",end="")
	print("")
	m-=1

# 4.
try:
	file=open('2.txt','r')
	file1=open('1.txt','a')
	file1.write(file.read())
except:
	print("file doesn't exist")

# file=open('2.txt','w')   #w,a,r+
# file.write('what is this\n')
# file.write('what is this')
# file.close( )

# 5.

def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)

def reversal(ar,n,d):
	g=gcd(n,d)
	for i in range(g):
		v=ar[i]
		j=(i-d+n)%n
		while j!=i:
			t=ar[j]
			ar[j]=v
			v=t
			j=(j-d+n)%n
		ar[j]=v
	return ar

n,d=[int(x) for x in input().split()]
ar=[int(x) for x in input().split()]

print(reversal(ar,n,d))

# 6.
print("".join(set(input())))

# 7.
import re 
  
def Find(string):  
    url = re.findall('http[s]?://[0-9a-zA-Z]+[-]?(?:.{1}(?:[-]?[0-9a-zA-Z]+)+)+(?:/{1}[0-9a-zA-Z]+)*/?', string) 
    return url 
      
string = 'My Profile: https://auth.geeksforgeeks.org / user / Chinmoy % 20Lenka / articles in the portal of http://www.geeksforgeeks.org/' 
print("Urls: ", Find(string))

# 8.
import cmath

a,b,c=[int(x) for x in input().split() ]

d=b**2 - 4*a*c
d=cmath.sqrt(d)

try:
	root1=(-b+d)/(2*a)
	root2=(-b-d)/(2*a)
	print(str(root1)+" "+str(root2))
except:
	try:
		root=-c/b
		print(root)
	except:
		if c==0:
			print("infinitely any solutions")
		else:
			print("solution doesn't exist")

# 9.
import calendar

m,y=[int(x) for x in input().split()]

print(calendar.calendar(y,2,1,6))
print(calendar.month(y,m))