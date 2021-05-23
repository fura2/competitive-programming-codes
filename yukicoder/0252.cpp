#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

void solve(){
	string s; cin>>s;
	int n=s.length();

	vector<int> P;
	rep(i,n-6) if(s.substr(i,7)=="problem") P.emplace_back(i);

	vector<int> dp(n,INF);
	for(int i=3;i<n;i++){
		int cnt=upper_bound(P.begin(),P.end(),i-10)-P.begin();
		if(s[i-3]!='g') cnt++;
		if(s[i-2]!='o') cnt++;
		if(s[i-1]!='o') cnt++;
		if(s[i-0]!='d') cnt++;
		dp[i]=min(dp[i-1],cnt);
	}

	int ans=INF;
	for(int i=7;i<n;i++){
		int cnt=0;
		if(s[i-6]!='p') cnt++;
		if(s[i-5]!='r') cnt++;
		if(s[i-4]!='o') cnt++;
		if(s[i-3]!='b') cnt++;
		if(s[i-2]!='l') cnt++;
		if(s[i-1]!='e') cnt++;
		if(s[i-0]!='m') cnt++;
		ans=min(ans,dp[i-7]+cnt);
	}
	printf("%d\n",ans);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
