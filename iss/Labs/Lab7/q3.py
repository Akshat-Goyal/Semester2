def UniqueSort(st):
	st=set(st.split(","))
	st=list(st)
	st.sort()
	print(",".join(st))

st=input()
UniqueSort(st)