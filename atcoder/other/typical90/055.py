import numpy as np
from numba import njit

@njit
def solve(n,p,q,a):
	ans=0
	for i in range(0,n):
		b1=a[i]%p
		for j in range(i+1,n):
			b2=b1*a[j]%p
			for k in range(j+1,n):
				b3=b2*a[k]%p
				for l in range(k+1,n):
					b4=b3*a[l]%p
					for m in range(l+1,n):
						b5=b4*a[m]%p
						if b5==q:
							ans+=1
	print(ans)

n,p,q=map(int,input().split())
a=np.array(list(map(int,input().split())),dtype=np.int64)
solve(n,p,q,a)
