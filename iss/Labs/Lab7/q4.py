def JoinIntegers(lst):
	return int("".join(map(str, lst)))

lst=input()
JoinIntegers(list(lst.split(",")))