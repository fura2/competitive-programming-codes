#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n+1);
	rep(i,n) scanf("%d",&a[i+1]);
	int m; scanf("%d",&m);
	vector<int> b(m+1);
	rep(j,m) scanf("%d",&b[j+1]);

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int dp[11][11][2];
	rep(i,n+1) rep(j,m+1) rep(k,2) dp[i][j][k]=-INF;
	dp[0][0][0]=dp[0][0][1]=0;
	rep(i,n+1) rep(j,m+1) {
		if(i<n && b[j]<a[i+1]) rep(k,i+1) dp[i+1][j][0]=max(dp[i+1][j][0],dp[k][j][1]+1);
		if(j<m && a[i]<b[j+1]) rep(k,j+1) dp[i][j+1][1]=max(dp[i][j+1][1],dp[i][k][0]+1);
	}

	int ans=0;
	rep(i,n+1) rep(j,m+1) rep(k,2) ans=max(ans,dp[i][j][k]);
	printf("%d\n",ans);

	return 0;
}
