#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint d,k; scanf("%d%lld%lld",&n,&d,&k);
	vector<pair<int,lint>> a(n);
	rep(i,n) scanf("%d%lld",&a[i].first,&a[i].second), a[i].first--;

	sort(a.begin(),a.end(),[](const auto& x,const auto& y){
		return x.second<y.second;
	});

	map<lint,lint> f[2];
	rep(i,n){
		int p;
		lint x; tie(p,x)=a[i];
		f[p][x]=i;
	}

	vector<int> dp(n,1);
	rep(i,n){
		int p;
		lint x; tie(p,x)=a[i];

		auto it=f[p].upper_bound(x);
		if(it!=f[p].end()){
			int i2=it->second;
			dp[i2]=max(dp[i2],dp[i]+1);
		}
		it=f[1-p].upper_bound(x+d+k*dp[i]);
		if(it!=f[1-p].end()){
			int i2=it->second;
			dp[i2]=max(dp[i2],dp[i]+1);
		}
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
