#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> d(n),c(m);
	rep(i,n) scanf("%d",&d[i]);
	rep(j,m) scanf("%d",&c[j]);

	vector dp(n+1,vector(m+1,INF));
	rep(j,m+1) dp[0][j]=0;
	rep(i,n) rep(j,m) dp[i+1][j+1]=min(dp[i+1][j],dp[i][j]+d[i]*c[j]);
	printf("%lld\n",dp[n][m]);

	return 0;
}
