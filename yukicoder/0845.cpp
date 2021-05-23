#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int d[16][16];
	memset(d,-1,sizeof d);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		d[u][v]=d[v][u]=max(d[u][v],c);
	}

	int dp[1<<16][16];
	memset(dp,-1,sizeof dp);
	rep(u,n) dp[1<<u][u]=0;
	rep(S,1<<n) rep(u,n) if(S>>u&1) {
		rep(v,n) if((S>>v&1)==0 && d[u][v]!=-1) {
			dp[S|1<<v][v]=max(dp[S|1<<v][v],dp[S][u]+d[u][v]);
		}
	}

	int ans=0;
	rep(S,1<<n) rep(u,n) ans=max(ans,dp[S][u]);
	printf("%d\n",ans);

	return 0;
}
