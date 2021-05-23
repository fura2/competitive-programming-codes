#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	vector dp(h,vector(w,vector(h+w,-INF)));
	dp[0][0][0]=0;
	dp[0][0][1]=B[0][0];
	rep(i,h) rep(j,w) {
		if(i+1<h){
			rep(k,h+w){
				dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
				if(k<h+w-1){
					dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+B[i+1][j]);
				}
			}
		}
		if(j+1<w){
			rep(k,h+w){
				dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
				if(k<h+w-1){
					dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]+B[i][j+1]);
				}
			}
		}
	}

	for(int k=1;k<h+w;k++) printf("%lld\n",dp[h-1][w-1][k]);

	return 0;
}
