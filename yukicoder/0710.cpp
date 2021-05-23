#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);

	vector dp(n+1,vector(100001,INF));
	dp[0][0]=0;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		rep(j,100001-a) dp[i+1][j+a]=min(dp[i+1][j+a],dp[i][j]);
		rep(j,100001) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+b);
	}

	int ans=INF;
	rep(j,100001) ans=min(ans,max(j,dp[n][j]));
	printf("%d\n",ans);

	return 0;
}
