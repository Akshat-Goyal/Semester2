from flask import Flask, request,jsonify
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///test.db'
db = SQLAlchemy(app)

class student(db.Model):
	rollno=db.Column(db.String(20), primary_key=True)
	name=db.Column(db.String(64), nullable=False)
	email=db.Column(db.String(255))

	def __init__(self,name,rollno,email):
		self.rollno=rollno
		self.name=name
		self.email=email

	def __repr__(self):
		return "student(name='%s', rollno='%s', email='%s')" %(self.name,self.rollno,self.email)

@app.route('/students/create',methods=['POST'])
def create():
	try:
		rollno=request.form['rollno']
		name=request.form['name']
		email=request.form['email']
		db.create_all()
		new=student(name,rollno,email)
		db.session.add(new)
		db.session.commit()
		return "Created successfully\n"
	except:
		db.session.rollback()
		return "Unable to create!\n"

@app.route('/students/<rollno>', methods=['GET'])
def fetch(rollno):
	try:
		db.create_all()
		stud=student.query.get(rollno)
		return stud.name+" "+stud.email+"\n"
	except:
		return "Unable to fetch!\n"

@app.route('/students/update/<rollno>', methods=['PUT'])
def update(rollno):
	try:
		db.create_all()
		stud=student.query.get(rollno)
		stud.name=request.form['name']
		stud.email=request.form['email']
		db.session.commit()
		return stud.name+" "+stud.email+"\n"
	except:
		db.session.rollback()
		return "Unable to update\n"

@app.route('/students/delete/<rollno>',methods=['DELETE'])
def delete(rollno):
	try:
		db.create_all()
		stud=student.query.get(rollno)
		db.session.delete(stud)
		db.session.commit()
		return "Deleted successfully!\n"
	except:
		db.session.rollback()
		return "Unable to delete!\n"

if __name__=='__main__':
	app.run(debug=True)