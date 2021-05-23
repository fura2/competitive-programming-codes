#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1e9+1;

int main(){
	int n,L,x[400],T[400]; scanf("%d%d",&n,&L);
	rep(i,n) scanf("%d",&x[i]), x[n+i]=x[i];
	rep(i,n) scanf("%d",&T[i]), T[n+i]=T[i];

	int d[400][400];
	rep(u,2*n) rep(v,2*n) d[u][v]=min(abs(x[u]-x[v]),L-abs(x[u]-x[v]));

	static int dp[400][400][201][2];
	rep(l,2*n) rep(r,2*n) rep(p,n+1) rep(i,2) dp[l][r][p][i]=INF;
	rep(l,2*n) rep(i,2) {
		int cost=min(x[l],L-x[l]);
		dp[l][l][cost<=T[l]?1:0][i]=cost;
	}

	for(int w=1;w<=n;w++) rep(l,2*n) {
		int r=l+w-1;
		if(r>=2*n) continue;

		rep(p,r-l+2){
			// もう片方の端に移動
			dp[l][r][p][1]=min(dp[l][r][p][1],dp[l][r][p][0]+d[l][r]);
			dp[l][r][p][0]=min(dp[l][r][p][0],dp[l][r][p][1]+d[r][l]);

			// 左端から一つ左に移動
			if(r-l+1<n && l>0){
				int p2=(dp[l][r][p][0]+d[l][l-1]<=T[l-1]?p+1:p);
				dp[l-1][r][p2][0]=min(dp[l-1][r][p2][0],dp[l][r][p][0]+d[l][l-1]);
			}

			// 右端から一つ右に移動
			if(r-l+1<n && r<2*n-1){
				int p2=(dp[l][r][p][1]+d[r][r+1]<=T[r+1]?p+1:p);
				dp[l][r+1][p2][1]=min(dp[l][r+1][p2][1],dp[l][r][p][1]+d[r][r+1]);
			}
		}
	}

	int ans=0;
	rep(l,2*n) rep(r,2*n) rep(p,n+1) rep(i,2) if(dp[l][r][p][i]<INF) ans=max(ans,p);
	printf("%d\n",ans);

	return 0;
}
