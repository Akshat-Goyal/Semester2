class Matrix(object):
	def __init__(self,row,col,matrix=None):
		self.row=row
		self.col=col

		if matrix is None:
			matrix=[0]*row
			for i in range(0,row):
				matrix[i]=[0]*col
		elif not len(matrix) == self.row:
			matrix=[0]*row
			for i in range(0,row):
				matrix[i]=[0]*col
		else:
			for i in range(0,self.row):
				if not len(matrix[i]) == self.col:
					matrix=[0]*row
					for i in range(0,row):
						matrix[i]=[0]*col

		self.matrix=matrix


	def transpose(self):
		mat = [[self.matrix[j][i] for j in range(self.row)] for i in range(self.col)]
		return mat

	def __str__(self):
		return str(self.matrix)

	def __getitem__(self, index):
		return self.matrix[index[0]][index[1]]

	def __setitem__(self, index, value):
		self.matrix[index[0]][index[1]] = value

	def __add__(self,m1):
		if (self.col != m1.col) or (self.row != m1.row):
			return "Addition not possible"
		else :
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			print(temp)
			for x in range(self.row):
				for y in range(self.col):
					temp[x][y] = self[x,y] + m1[x,y]
			return Matrix(self.row, self.col,temp)

	def __sub__(self,m1):
		if (self.col != m1.col) or (self.row != m1.row):
			return "Subtraction not possible"
		else :
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			for x in range(self.row):
				for y in range(self.col):
					temp[x][y] = self[x,y] - m1[x,y]
			return Matrix(self.col, self.row,temp)

	def __mul__(self,m1):
		if (self.col != m1.col) or (self.row != m1.row):
			return "Multiplication not possible"
		else :
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			for x in range(self.row):
				for y in range(self.col):
					a=0
					for i in range(self.row):
						a=a+(self[x,i]*m1[i,y])
					temp[x][y]=a

		return Matrix(self.col, self.row, temp)

	def __pow__(self,m1):
		if (self.col != m1.col) or (self.row != m1.row):
			return "Subtraction not possible"
		else:
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			for x in range(self.row):
				for y in range(self.col):
					temp[x][y] = self[x,y] * m1[x,y]
			return Matrix(self.col, self.row,temp)

	def __eq__(self,m1):
		if (self.col != m1.col) or (self.row != m1.row):
			return "Operation not possible"
		else :
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			for x in range(self.row):
				for y in range(self.col):
					temp[x][y] = self[x,y] == m1[x,y]
			return temp

	def __lt__(self,m1):
		if (m1.col != m1.col) or (self.row != m1.row):
			return "Operation not possible"
		else :
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			for x in range(self.row):
				for y in range(self.col):
					temp[x][y] = self[x,y] < m1[x,y]
			return temp

	def __le__(self,new):
		if (self.col != new.col) or (self.row != new.row):
			return "Operation not possible"
		else :
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			for x in range(self.row):
				for y in range(self.col):
					temp[x][y] = self[x,y] <= new[x,y]
			return temp

	def __gt__(self,new):
		if (self.col != new.col) or (self.row != new.row):
			return "Operation not possible"
		else :
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			for x in range(self.row):
				for y in range(self.col):
					temp[x][y] = self[x,y] > new[x,y]
			return temp

	def __ge__(self,new):
		if (self.col != new.col) or (self.row != new.row):
			return "Operation not possible"
		else :
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			for x in range(self.row):
				for y in range(self.col):
					temp[x][y] = self[x,y] >= new[x,y]
			return temp

	def __ne__(self,new):
		if (self.col != new.col) or (self.row != new.row):
			return "Operation not possible"
		else :
			temp = [[0 for x in range(self.col)] for y in range(self.row)]
			for x in range(self.row):
				for y in range(self.col):
					temp[x][y] = self[x,y] != new[x,y]
			return temp


class Vector(Matrix):
	def __init__(self,rows,args,*kwargs):
		if len(args) == 0:
			Matrix.__init__(self,1,rows)
		else:
			b = []
			for i in args[0]:
				b.insert(0,[i])
			Matrix.__init__(self,1,rows,b)
	
	def __getitem__(self, index):
		return self.matrix[index][0]

	def __setitem__(self, index, value):
		self.matrix[index][0] = value

	def norm(self):
		ret=0
		for a in range(self.rows):
			ret = ret + pow(self.matrix[a][0],2)
		return pow(ret,0.5)

	def __mod__(self,new):
		if self.rows == new.rows:
			temp = [] 
			for a in range(self.rows):
				temp.append(self[a]*new[a])
			return vector(self.rows,temp)
		else:
			return "not possible"

	def transpose(self):
		print("not possible")

m = Matrix(2,2,[[2,3],[1,0]])
m1 = Matrix(2,2,[[2,3],[1,0]])
