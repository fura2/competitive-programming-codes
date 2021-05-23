#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	int m;
	for(m=1;min(k,m)*m<n;m++);
	static char ans[1000][1001];
	rep(i,m){
		rep(j,m) ans[i][j]='.';
		rep(j,min(k,m)) if(n>0) ans[i][(i+j)%m]='#', n--;
	}

	printf("%d\n",m);
	rep(i,m) puts(ans[i]);

	return 0;
}
