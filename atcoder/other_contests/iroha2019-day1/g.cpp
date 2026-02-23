#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector dp(n+1,vector(m+1,-1LL));
	dp[0][0]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		for(int x=max(i-k,0);x<i;x++) if(dp[x][j-1]!=-1) {
			dp[i][j]=max(dp[i][j],dp[x][j-1]+a[i-1]);
		}
	}

	lint ans=-1;
	for(int i=max(n-k+1,0);i<=n;i++) ans=max(ans,dp[i][m]);
	printf("%lld\n",ans);

	return 0;
}
