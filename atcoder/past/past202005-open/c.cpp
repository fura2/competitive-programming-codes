#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,r,n; scanf("%d%d%d",&a,&r,&n);

	if(r>1){
		rep(i,n-1){
			if(a>1000000000/r) return puts("large"),0;
			a*=r;
		}
	}
	printf("%d\n",a);

	return 0;
}
