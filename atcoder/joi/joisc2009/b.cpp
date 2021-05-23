// Day 1: Stamps

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n;
	string s; cin>>n>>s;

	vector<pair<int,int>> dp(n+1,{INF,INF});
	dp[1]={s[0]=='I'?0:1,1};
	if(n>=2 && s.substr(0,2)=="OI") dp[2]={1,1};
	for(int i=2;i<=n;i++){
		dp[i]=min(dp[i],{dp[i-1].first+1,dp[i-1].second});
		int cost=0;
		if(s[i-2]=='I') cost++;
		if(s[i-1]=='O') cost++;
		dp[i]=min(dp[i],{dp[i-2].first+cost,dp[i-2].second+2});
	}
	cout<<dp[n].first<<'\n'<<dp[n].second<<'\n';

	return 0;
}
