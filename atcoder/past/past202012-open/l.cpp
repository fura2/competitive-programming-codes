#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s,t; cin>>n>>s>>t;

	vector dp(n,vector(n+1,false));
	rep(i,n) dp[i][i]=true;
	for(int w=1;w<=n;w++){
		rep(l,n-w+1){
			int r=l+w;
			for(int i=l+1;i<r;i++){
				if(dp[l][i] && dp[i][r]){
					dp[l][r]=true;
				}
				if(i<r-1 && s[l]==t[0] && s[i]==t[1] && s[r-1]==t[2] && dp[l+1][i] && dp[i+1][r-1]){
					dp[l][r]=true;
				}
			}
		}
	}

	vector dp2(n,vector(n+1,0));
	for(int w=1;w<=n;w++){
		rep(l,n-w+1){
			int r=l+w;
			for(int i=l+1;i<r;i++){
				if(dp[l][r]) dp2[l][r]=(r-l)/3;
				dp2[l][r]=max(dp2[l][r],dp2[l][i]+dp2[i][r]);
			}
		}
	}
	printf("%d\n",dp2[0][n]);

	return 0;
}
