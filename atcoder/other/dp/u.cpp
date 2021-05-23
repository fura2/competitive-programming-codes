#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	lint a[16][16];
	rep(i,n) rep(j,n) scanf("%lld",&a[i][j]);

	lint cost[1<<16]={};
	rep(S,1<<n){
		rep(i,n) if(S>>i&1) rep(j,i) if(S>>j&1) cost[S]+=a[i][j];
	}

	lint dp[1<<16];
	rep(S,1<<n) dp[S]=-INF;
	dp[0]=0;
	rep(S,1<<n){
		for(int T=S;;T=(T-1)&S){
			dp[S]=max(dp[S],dp[T]+cost[S&~T]);
			if(T==0) break;
		}
	}
	printf("%lld\n",dp[(1<<n)-1]);

	return 0;
}
