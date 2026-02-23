n=int(input())
S=set()
for i in range(n):
	s=input()
	if s not in S:
		print(i+1)
		S.add(s)
