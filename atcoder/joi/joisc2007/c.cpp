// Day 1: Mall

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w,a,b; scanf("%d%d%d%d",&w,&h,&b,&a);
	lint c[1001][1001];
	rep(i,h) rep(j,w) {
		int x; scanf("%d",&x);
		if(x==-1) x=1e8;
		c[i+1][j+1]=x+c[i+1][j]+c[i][j+1]-c[i][j];
	}

	lint ans=1e8;
	rep(i,h-a+1) rep(j,w-b+1) ans=min(ans,c[i+a][j+b]-c[i+a][j]-c[i][j+b]+c[i][j]);
	printf("%lld\n",ans);

	return 0;
}
