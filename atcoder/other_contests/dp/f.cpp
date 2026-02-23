#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int m=s.length(),n=t.length();

	static int dp[3001][3001],prev[3001][3001];
	rep(i,m) prev[i+1][0]=1;
	rep(j,n) prev[0][j+1]=0;
	rep(i,m) rep(j,n) {
		dp[i+1][j+1]=max({dp[i+1][j],dp[i][j+1],dp[i][j]+(s[i]==t[j]?1:0)});
		if(dp[i+1][j+1]==dp[i+1][j]){
			prev[i+1][j+1]=0;
		}
		else if(dp[i+1][j+1]==dp[i][j+1]){
			prev[i+1][j+1]=1;
		}
		else{
			prev[i+1][j+1]=2;
		}
	}

	string ans;
	int i=m,j=n;
	while(i>0 || j>0){
		if(prev[i][j]==0){
			j--;
		}
		else if(prev[i][j]==1){
			i--;
		}
		else{
			i--;
			j--;
			ans+=s[i];
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';

	return 0;
}
