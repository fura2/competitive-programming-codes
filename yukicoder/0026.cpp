#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,m){
		int p,q; scanf("%d%d",&p,&q);
		if     (n==p) n=q;
		else if(n==q) n=p;
	}
	printf("%d\n",n);

	return 0;
}
