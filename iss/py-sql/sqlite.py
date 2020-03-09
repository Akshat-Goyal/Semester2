import sqlite3

mydb=sqlite3.connect('test.db')

mycursor=mydb.cursor()

mycursor.execute("CREATE table lite(id int(3), name varchar(64))")