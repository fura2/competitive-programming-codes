#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	int A[15][15]={};
	rep(u,n) for(int v=u+1;v<n;v++) {
		scanf("%d",&A[u][v]);
		A[v][u]=A[u][v];
	}

	if(n==2){
		puts("0 0");
		return 0;
	}

	int dp[1<<15][15];
	rep(S,1<<n) rep(u,n) dp[S][u]=INF;
	dp[1][0]=0;
	rep(S,1<<n) rep(u,n) if(S>>u&1) {
		rep(v,n) if(~S>>v&1) {
			dp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+A[u][v]);
		}
	}

	int ans=INF;
	rep(u,n) ans=min(ans,dp[(1<<n)-1][u]+A[u][0]);
	printf("%d %d\n",n,ans);

	return 0;
}
