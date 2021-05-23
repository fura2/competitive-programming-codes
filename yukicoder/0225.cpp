#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m;
	string s,t; cin>>n>>m>>s>>t;

	int dp[1001][1001];
	rep(i,n+1) dp[i][0]=i;
	rep(j,m+1) dp[0][j]=j;
	rep(i,n) rep(j,m) {
		// 挿入 or 削除
		dp[i+1][j+1]=min(dp[i][j+1]+1,dp[i+1][j]+1);
		// 変更
		dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(s[i]==t[j]?0:1));
	}
	printf("%d\n",dp[n][m]);

	return 0;
}
