import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="db3",
)

mycursor = mydb.cursor()

# mycursor.execute("CREATE TABLE dept(deptno INT(3), deptname VARCHAR(255), PRIMARY KEY(deptno))")
# mycursor.execute("CREATE TABLE emp (empno INT(3), ename VARCHAR(255), salary INT(10), mgrno INT(3), deptno INT(3), dob DATE, PRIMARY KEY(empno), FOREIGN KEY (deptno) REFERENCES dept(deptno))")

# mycursor.execute("DESCRIBE emp")
# y = mycursor.fetchall()

# 1.
# mycursor.execute("SELECT ename FROM emp where deptno IS NULL")

# 2.
# n = 2
# mycursor.execute("SELECT ename FROM emp ORDER BY salary LIMIT 1 OFFSET "+ str(n-1))

# 3.
# mycursor.execute("SELECT ename,mgrno FROM emp")

# 5.
# mycursor.execute("SELECT salary FROM emp")

# count = 0
# total = 0
# for i in mycursor:
# 	count+=1	
# 	total+=i[0]

# total/=count
# print(total)
# mycursor.execute("SELECT ename FROM emp where salary > "+str(total))

# 6.
# mycursor.execute("SELECT ename FROM emp where ename LIKE '%Ab%'")

for i in mycursor:
	print(i)