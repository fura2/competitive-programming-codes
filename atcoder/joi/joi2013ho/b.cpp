#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int m,n;
	char s[2001],t[2001];
	scanf("%d%d%s%s",&m,&n,s,t);

	static int dp[2][2001][2001];
	rep(i,m+1) rep(j,n+1) dp[1][i][j]=-INF;
	for(int i=m;i>=0;i--) for(int j=n;j>=0;j--) {
		if(i<m){
			int c=(s[i]=='I'?1:0);
			dp[c][i][j]=max(dp[c][i][j],dp[1-c][i+1][j]+1);
		}
		if(j<n){
			int c=(t[j]=='I'?1:0);
			dp[c][i][j]=max(dp[c][i][j],dp[1-c][i][j+1]+1);
		}
	}

	int ans=0;
	rep(i,m+1) rep(j,n+1) ans=max(ans,dp[1][i][j]);
	printf("%d\n",ans);

	return 0;
}
