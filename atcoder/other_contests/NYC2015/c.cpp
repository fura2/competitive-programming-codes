#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	int n=s.length(),m=t.length();

	static bool dp[5001][5001]={}; // dp[i][j] = (s[0,i) から t[0,j) が作れるか)
	dp[0][0]=true;
	rep(i,n){
		rep(j,m){
			if(dp[i][j] && t[j]==s[i]){
				dp[i+1][j+1]=true;
				if(j<m-1 && t[j+1]!=s[i]){
					for(j++;j<=m;j++) dp[i+1][j]=true;
				}
			}
		}
	}
	puts(dp[n][m]?"Yes":"No");

	return 0;
}
