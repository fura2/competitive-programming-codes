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
		if(B[i][j]=='.'){
			if(i>0) dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
			if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
		}
		else{
			if(i>0) dp[i][j]=min(dp[i][j],dp[i-1][j]+1+i+j);
			if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+1+i+j);
		}
	}
	printf("%d\n",dp[h-1][w-1]);

	return 0;
}
