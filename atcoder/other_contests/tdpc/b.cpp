#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,a[1000],b[1000]; cin>>n>>m;
	rep(i,n) cin>>a[i];
	rep(i,m) cin>>b[i];

	reverse(a,a+n);
	reverse(b,b+m);

	int asum[1001],bsum[1001];
	asum[0]=bsum[0]=0;
	rep(i,n) asum[i+1]=asum[i]+a[i];
	rep(j,m) bsum[j+1]=bsum[j]+b[j];

	int dp[1001][1001];
	dp[0][0]=0;
	rep(i,n) dp[i+1][0]=a[i]+asum[i]-dp[i][0];
	rep(j,m) dp[0][j+1]=b[j]+bsum[j]-dp[0][j];
	rep(i,n) rep(j,m) dp[i+1][j+1]=asum[i+1]+bsum[j+1]-min(dp[i][j+1],dp[i+1][j]);
	cout<<dp[n][m]<<endl;

	return 0;
}
