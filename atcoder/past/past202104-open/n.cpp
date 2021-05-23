#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,h; scanf("%d%d",&n,&h);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld%lld",&a[i],&b[i]);

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return a[i]*b[j]>a[j]*b[i];
	});

	vector<lint> dp(h+1,-INF);
	dp[h]=0;
	for(int i:p){
		rep(x,h+1) if(dp[x]!=-INF) {
			int x2=max(x-b[i],0LL);
			dp[x2]=max(dp[x2],dp[x]+a[i]*x);
		}
	}
	printf("%lld\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
