def rec(n,s,dep):
	if n==0:
		if dep==0:
			print(s)
		return
	rec(n-1,s+'(',dep+1)
	if dep>0:
		rec(n-1,s+')',dep-1)
	return

n=int(input())
rec(n,'',0)
