from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask import request
from flask import jsonify

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:////tmp/test.db'
db = SQLAlchemy(app)

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    rollnumber = db.Column(db.Integer, unique=True)
    name = db.Column(db.String(120), unique=True)
    email = db.Column(db.String(120), unique=True)

    def __init__(self, rollnumber, name, email):
        self.rollnumber=rollnumber
        self.name = name
        self.email = email

    def __repr__(self):
        return '<User %r>' % self.name

@app.route("/students/create/", methods=["GET","POST"])
def userAdd():
    rollnumber=request.form['rollnumber']
    name=request.form['name']
    email= request.form['email']
    db.create_all()
    new_person=User(rollnumber,name, email)
    db.session.add(new_person)
    db.session.commit()
    temp ={}
    temp['status']=(type(new_person)==User)
    return jsonify(temp)

@app.route("/students/",methods=["GET"])
def userFetch():
    db.create_all()
    allUsers=User.query.all()
    strf = '['
    for user in allUsers:
        strf += "{"+str(user.rollnumber)+" ," + user.name + " ," + user.email + "}" + ","
    strf += "]" 
    return strf

@app.route("/students/<rolln>", methods=["GET","POST"])
def userUpdate(rolln):
    db.create_all()
    allUsers=User.query.all()
    roll=request.form['rollnumber']
    name=request.form['name']
    email=request.form['email']
    new_person = User(roll, name, email)
    strf = ''
    for user in User.query.all():
        if user.rollnumber == rolln:
            db.session.delete(user)
            db.session.add(new_person)
            strf += '{student = {' + 'rollnumber:' + user.rollnumber + ", " + 'name:' + user.name + ", " + 'email:' + user.email + '}' + "}\n"
    strf += '\n'
    db.session.commit()
    return strf


if __name__ == "__main__":
    app.run(host='127.0.0.1', port=5000)