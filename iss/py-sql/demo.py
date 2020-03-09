import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="db3",
)

mycursor = mydb.cursor()

# mycursor.execute("CREATE TABLE customers (id INT , name VARCHAR(255), address VARCHAR(255))")
# mycursor.execute("ALTER TABLE customers MODIFY COLUMN id INT AUTO_INCREMENT PRIMARY KEY")
# sql = "INSERT INTO customers(name, address) VALUES(%s,%s)"
# val = ('john', 'US')
# mycursor.execute(sql,val)
# mydb.commit()
# print(mycursor.rowcount)
mycursor.execute("SELECT * FROM customers ORDER BY name DESC")

y = mycursor.fetchall()

for x in y :
	print(x)