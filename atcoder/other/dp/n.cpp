#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<lint> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+a[i];

	lint dp[400][401];
	rep(l,n) rep(r,n+1) dp[l][r]=INF;
	rep(l,n) dp[l][l+1]=0;
	for(int w=2;w<=n;w++) rep(l,n-w+1) {
		int r=l+w;
		for(int m=l+1;m<r;m++) dp[l][r]=min(dp[l][r],dp[l][m]+dp[m][r]+sum[r]-sum[l]);
	}
	printf("%lld\n",dp[0][n]);

	return 0;
}
