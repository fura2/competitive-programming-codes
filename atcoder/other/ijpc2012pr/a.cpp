#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int replace(int n,char* s){
	vector<vector<int> > dp(n+1,vector<int>(5,INF));
	rep(i,n+1) dp[i][0]=0;
	rep(i,n){
		rep(j,5){
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			if(j<4){
				if(s[i]=="IJPC"[j]){
					dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
				}
				else{
					dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
				}
			}
		}
	}
	return dp[n][4];
}
