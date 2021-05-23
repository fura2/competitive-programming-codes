#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> a[150];
	rep(i,n){
		int k; scanf("%d",&k);
		rep(j,k){
			int x,d; scanf("%d%d",&x,&d); x--;
			a[i].emplace_back(x,d);
		}
	}

	static int dp[150][80][1000];
	rep(i,n) rep(j,m+1) rep(x,1000) dp[i][j][x]=INF;
	rep(x,1000){
		dp[0][0][x]=0;
		if(m>0) dp[1][1][x]=0;
	}
	rep(i,n-1) rep(j,m+1) {
		for(auto [x1,d1]:a[i]) {
			for(auto [x2,d2]:a[i+1]) {
				dp[i+1][j][x2]=min(dp[i+1][j][x2],dp[i][j][x1]+(d1+d2)*abs(x2-x1));
			}

			if(i+2>=n || j+1>m) continue;
			for(auto [x2,d2]:a[i+2]) {
				dp[i+2][j+1][x2]=min(dp[i+2][j+1][x2],dp[i][j][x1]+(d1+d2)*abs(x2-x1));
			}
		}
	}

	int ans=INF;
	rep(j,m+1) rep(x,1000) {
		ans=min(ans,dp[n-1][j][x]);
		if(j<m) ans=min(ans,dp[n-2][j][x]);
	}
	printf("%d\n",ans);

	return 0;
}
