#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	vector<lint> dp(n);
	for(int i=2;i<n;i++){
		dp[i]=dp[i-1];
		if(a[i-2]+a[i-1]>a[i]){
			dp[i]=max(dp[i],a[i-2]+a[i-1]+a[i]);
		}
	}

	lint ans=0;
	for(int i=5;i<n;i++){
		if(dp[i-3]>0 && a[i-2]+a[i-1]>a[i]){
			ans=max(ans,dp[i-3]+a[i-2]+a[i-1]+a[i]);
		}
	}
	for(int i=5;i<n;i++){
		rep(S,1<<6) if(popcount(S)==3) {
			vector<lint> x,y;
			rep(j,6){
				if(S>>j&1) x.emplace_back(a[i-5+j]);
				else       y.emplace_back(a[i-5+j]);
			}
			if(x[0]+x[1]>x[2] && y[0]+y[1]>y[2]){
				ans=max(ans,a[i-5]+a[i-4]+a[i-3]+a[i-2]+a[i-1]+a[i]);
			}
		}
	}

	printf("%lld\n",ans);

	return 0;
}
