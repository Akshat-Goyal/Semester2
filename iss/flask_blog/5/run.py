from flaskblog import app

if __name__ == '__main__':
	app.run(debug=True)

# from flaskblog import app,db
# from flaskblog.models import User, Post
 
# @app.shell_context_processor
# def make_shell_context():
# 	return {'db': db, 'User': User, 'Post': Post}
 # return {'db': db, 'User': User, 'Post': Post}