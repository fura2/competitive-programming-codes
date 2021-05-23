#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int d[14][14]={};
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		d[u][v]+=c;
	}

	int dp[1<<14]={};
	rep(S,1<<n){
		rep(u,n) if(S>>u&1) {
			int sum=0;
			rep(v,n) if(v!=u && S>>v&1) sum+=d[v][u];
			dp[S]=max(dp[S],dp[S&~(1<<u)]+sum);
		}
	}
	printf("%d\n",dp[(1<<n)-1]);

	return 0;
}
