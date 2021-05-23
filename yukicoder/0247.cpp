#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int W,n; scanf("%d%d",&W,&n);

	vector<int> dp(W+1,INF);
	dp[0]=0;
	rep(i,n){
		int w; scanf("%d",&w);
		rep(a,W-w+1) dp[a+w]=min(dp[a+w],dp[a]+1);
	}
	printf("%d\n",dp[W]<INF?dp[W]:-1);

	return 0;
}
