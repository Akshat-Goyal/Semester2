def isLeapYear(year):
	if year%400 == 0 :
		return True
	else:
		if year%4 == 0:
			if year%100 == 0:
				return False
			else:
				return True
		else
			return False

y=input()
isLeapYear(int(y))
