#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	bool dp[300][301]={}; // dp[l][r] = (is s[l,r] removable?)
	rep(i,n) dp[i][i]=true;
	for(int d=3;d<=n;d+=3) rep(l,n-d+1) {
		int r=l+d;
		for(int i=l+3;i<r;i+=3){
			dp[l][r]|=dp[l][i]&dp[i][r];
		}
		if(s[l]=='i' && s[r-1]=='i'){
			for(int i=l+2;i<r;i+=3) if(s[i-1]=='w') {
				dp[l][r]|=dp[l+1][i-1]&dp[i][r-1];
			}
		}
	}

	vector<pair<int,int>> I;
	rep(r,n+1) rep(l,r) if(dp[l][r]) I.emplace_back(l,r);

	int dp2[301]={};
	for(auto J:I){
		int l=J.first,r=J.second;
		rep(i,l+1) dp2[r]=max(dp2[r],dp2[i]+(r-l)/3);
	}
	cout<<*max_element(dp2,dp2+301)<<endl;

	return 0;
}
