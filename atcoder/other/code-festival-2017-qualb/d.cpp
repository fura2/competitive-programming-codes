#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	vector<int> pos={-1};
	rep(i,n) if(s[i]=='0') pos.emplace_back(i);
	pos.emplace_back(n);

	vector<vector<int>> Ev(n); // right endpoint -> left endpoint
	for(int i=1;i<n-1;i++) if(s[i-1]=='1' && s[i]=='0' && s[i+1]=='1') {
		for(int x=i-1;x>=0&&s[x]=='1';x--) Ev[i+1].emplace_back(x);
		for(int x=i+2;x< n&&s[x]=='1';x++) Ev[x].emplace_back(i-1);
	}

	vector<int> dp(n+1);
	rep(x,n){
		dp[x+1]=dp[x];
		for(int l:Ev[x]){
			dp[x+1]=max(dp[x+1],dp[l]+x-l-1);
		}
	}
	cout<<dp[n]<<'\n';

	return 0;
}
