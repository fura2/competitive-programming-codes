#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,l,x; scanf("%d%d%d%d",&n,&m,&l,&x);

	int cur=0,nxt=1;
	int dp[2][1000];
	rep(j,m) dp[cur][j]=x;
	dp[cur][0]=0;
	rep(i,n){
		int a; scanf("%d",&a);

		rep(j,m) dp[nxt][j]=dp[cur][j];
		rep(j,m) dp[nxt][(j+a)%m]=min(dp[nxt][(j+a)%m],dp[cur][j]+(j+a)/m);

		swap(cur,nxt);
	}

	puts(dp[cur][l]<x?"Yes":"No");

	return 0;
}
