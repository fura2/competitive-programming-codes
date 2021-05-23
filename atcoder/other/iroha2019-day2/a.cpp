#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int n=s.length();

	vector dp(n+1,vector(n+1,0));
	rep(i,n+1) rep(j,n+1) {
		if(i<n) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		if(j<n) dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
		if(i<n && j<n && s[i]==t[j]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
	}
	cout<<dp[n][n]+1<<'\n';

	return 0;
}
