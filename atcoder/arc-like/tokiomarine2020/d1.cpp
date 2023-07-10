#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> v(n),w(n);
	rep(i,n) scanf("%d%d",&v[i],&w[i]);

	vector<vector<int>> dp(min(1<<9,n),vector<int>(100001,-INF));
	rep(i,min(1<<9,n)){
		if(i==0){
			dp[i][0]=0;
		}
		else{
			dp[i]=dp[(i-1)/2];
		}
		for(int a=100000;a>=w[i];a--) dp[i][a]=max(dp[i][a],dp[i][a-w[i]]+v[i]);
		rep(a,100000) dp[i][a+1]=max(dp[i][a+1],dp[i][a]);
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int u,W; scanf("%d%d",&u,&W); u--;

		vector<int> V;
		while(u>=min(1<<9,n)){
			V.emplace_back(u);
			u=(u-1)/2;
		}

		int ans=0;
		int m=V.size();
		rep(S,1<<m){
			int wsum=0,vsum=0;
			rep(i,m) if(S>>i&1) {
				wsum+=w[V[i]];
				vsum+=v[V[i]];
			}
			if(wsum>W) continue;

			ans=max(ans,dp[u][W-wsum]+vsum);
		}
		printf("%d\n",ans);
	}

	return 0;
}
