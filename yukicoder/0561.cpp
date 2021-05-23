#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,d; scanf("%d%d",&n,&d);

	lint dp[101][2];
	rep(i,n+1) rep(j,2) dp[i][j]=-INF;
	dp[0][0]=0;
	rep(i,n){
		int t,k; scanf("%d%d",&t,&k);
		dp[i+1][0]=max(dp[i][0],dp[i][1]-d)+t;
		dp[i+1][1]=max(dp[i][0]-d,dp[i][1])+k;
	}
	printf("%lld\n",max(dp[n][0],dp[n][1]));

	return 0;
}
