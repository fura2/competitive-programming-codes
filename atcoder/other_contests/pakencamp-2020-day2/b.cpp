#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector dp(h,vector(w,INF));
	dp[0][0]=0;
	rep(i,h) rep(j,w) {
		if(i+1<h) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(B[i][j]=='E'?1:0));
		if(j+1<w) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+(B[i][j]=='S'?1:0));
	}
	printf("%d\n",dp[h-1][w-1]+(B[h-1][w-1]=='S'?1:0));

	return 0;
}
