#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector a(n,vector(n,0));
	rep(i,n) rep(j,i+1) scanf("%d",&a[i][j]);

	vector dp(n,vector(n,0));
	dp[0][0]=a[0][0];
	rep(i,n-1) rep(j,i+1) rep(k,2) {
		dp[i+1][j+k]=max(dp[i+1][j+k],dp[i][j]+a[i+1][j+k]);
	}
	printf("%d\n",*max_element(dp[n-1].begin(),dp[n-1].end()));

	return 0;
}
