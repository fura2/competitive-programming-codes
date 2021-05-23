#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<pair<lint,lint>> p(n);
	rep(i,n) scanf("%lld%lld",&p[i].first,&p[i].second);

	sort(p.begin(),p.end());

	vector<lint> dp(n);
	dp[0]=p[0].first+p[0].second;
	for(int i=1;i<n;i++){
		dp[i]=max(p[i].first+p[i].second,dp[i-1]+p[i].second);
	}

	lint ans=0;
	rep(i,n) ans=max(ans,dp[i]-p[i].first);
	printf("%lld\n",ans);

	return 0;
}
