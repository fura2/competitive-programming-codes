#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> a(n);
	rep(i,n){
		rep(j,m){
			lint tmp; scanf("%lld",&tmp);
			a[i]+=tmp;
		}
	}

	vector dp(n+1,vector(2,-INF));
	dp[0][1]=0;
	rep(i,n){
		dp[i+1][0]=max(dp[i][0],dp[i][1]+a[i]);
		dp[i+1][1]=max(dp[i][1],dp[i][0]-a[i]);
	}
	printf("%lld\n",max(dp[n][0],dp[n][1]));

	return 0;
}
