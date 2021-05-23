#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m; cin>>n>>m;

	lint dp[1<<10];
	rep(S,1<<n) dp[S]=INF;
	dp[0]=0;
	rep(_,m){
		string s;
		lint cost; cin>>s>>cost;
		int b=0;
		rep(i,n) if(s[i]=='Y') b|=1<<i;

		rep(S,1<<n) dp[S|b]=min(dp[S|b],dp[S]+cost);
	}

	cout<<(dp[(1<<n)-1]<INF?dp[(1<<n)-1]:-1)<<'\n';

	return 0;
}
