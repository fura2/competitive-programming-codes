#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int solve(string s,string t){
	int n=s.length();

	vector cost(n+1,vector(n+1,0));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		cost[i][j]=cost[i-1][j-1]+(s[i-1]==t[j-1]?1:0);
	}

	vector dp(n+1,vector(n+1,INF));
	dp[n][n]=0;
	for(int i=n;i>=0;i--) for(int j=n;j>=0;j--) {
		if(i>0) dp[i-1][j]=min(dp[i-1][j],dp[i][j]+cost[i][j]);
		if(j>0) dp[i][j-1]=min(dp[i][j-1],dp[i][j]+cost[i][j]);
	}
	return dp[0][0];
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int ans=0;
	rep(j,w-1){
		string s,t;
		rep(i,h){
			s+=B[i][j];
			t+=B[i][j+1];
		}
		ans+=solve(s,t);
	}
	cout<<ans<<'\n';

	return 0;
}
