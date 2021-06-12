def main():
	n,l=map(int,input().split())
	k=int(input())
	a=list(map(int,input().split()))

	lo=0
	hi=l
	while hi-lo>1:
		mi=(lo+hi)//2

		cnt=0
		pre=0
		for i in range(n):
			if a[i]-pre>=mi and cnt<k:
				cnt+=1
				pre=a[i]
		if cnt==k and l-pre>=mi:
			lo=mi
		else:
			hi=mi
	print(lo)
	return

main()
