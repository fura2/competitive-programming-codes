#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m,x0; scanf("%d%d%d",&n,&m,&x0);
	vector<int> a(n+1);
	rep(i,n+1) scanf("%d",&a[i]);

	vector dp(n+1,vector(m+1,-INF));
	dp[0][0]=x0;
	for(int i=1;i<=n;i++) rep(j,m+1) {
		dp[i][j]=dp[i-1][j];
		if(j>0){
			rep(k,i){
				dp[i][j]=max(dp[i][j],dp[k][j-1]%a[k]+dp[k][j-1]/a[k]*a[i]);
			}
		}
	}

	lint ans=x0;
	rep(i,n+1) rep(j,m+1) ans=max(ans,dp[i][j]);
	printf("%lld\n",ans);

	return 0;
}
