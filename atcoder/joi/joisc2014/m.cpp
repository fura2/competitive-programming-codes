// Day 4: Straps

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	vector<lint> b(n);
	rep(i,n) scanf("%d%lld",&a[i],&b[i]);

	vector<pair<int,lint>> p;
	vector<lint> q;
	rep(i,n){
		if(a[i]>0){
			p.emplace_back(a[i]-1,b[i]);
		}
		else if(b[i]>0){
			q.emplace_back(b[i]);
		}
	}
	sort(q.rbegin(),q.rend());

	vector<lint> dp(n+1,-INF);
	dp[1]=0;
	for(auto [x,y]:p){
		for(int z=n;z>=0;z--) if(dp[z]>-INF) dp[min(z+x,n)]=max(dp[min(z+x,n)],dp[z]+y);
	}

	vector<lint> cum(q.size()+1);
	rep(i,q.size()) cum[i+1]=cum[i]+q[i];

	lint ans=0;
	rep(x,n+1) if(dp[x]>-INF) ans=max(ans,dp[x]+cum[min<int>(x,q.size())]);
	printf("%lld\n",ans);

	return 0;
}
