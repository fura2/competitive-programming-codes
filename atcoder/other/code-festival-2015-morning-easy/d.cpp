#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int lcs(string s,string t){
	int m=s.length(),n=t.length();
	int dp[100][100]={};
	rep(i,m) rep(j,n) {
		dp[i+1][j+1]=max({dp[i+1][j],dp[i][j+1],dp[i][j]+(s[i]==t[j]?1:0)});
	}
	return dp[m][n];
}

int main(){
	int n;
	string s; cin>>n>>s;

	int ans=n;
	rep(i,n-1) ans=min(ans,n-2*lcs(s.substr(0,i+1),s.substr(i+1)));
	cout<<ans<<'\n';

	return 0;
}
