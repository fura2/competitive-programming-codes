#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,d; scanf("%d%d",&n,&d);
	static lint a[2000][2000];
	rep(i,d) rep(j,n) scanf("%lld",&a[i][n-1-j]);

	static lint asum[2000][2001];
	rep(i,d) rep(j,n) asum[i][j+1]=asum[i][j]+a[i][j];

	// dp[i][j] = ( i 日目に左の皿に j 枚乗っているときの最小コスト)
	static lint dp[2001][2001];
	rep(i,d+1) rep(j,n+1) dp[i][j]=INF;
	dp[0][n]=0;
/* naive O(D*N^2) DP
	rep(i,d){
		for(int j=n;j>=0;j--){
			for(int k=j;k<=n;k++){
				dp[i+1][j]=min(dp[i+1][j],dp[i][k])+abs(asum[i][n]-2*asum[i][j]);
			}
		}
	}
*/
	static lint dp_min[2001][2001];
	rep(i,d){
		for(int j=n;j>=0;j--){
			dp[i+1][j]=dp_min[i][j]+abs(asum[i][n]-2*asum[i][j]);
		}
		dp_min[i+1][n]=dp[i+1][n];
		for(int j=n-1;j>=0;j--) dp_min[i+1][j]=min(dp[i+1][j],dp_min[i+1][j+1]);
	}

	printf("%lld\n",*min_element(dp[d],dp[d]+n+1));

	return 0;
}
