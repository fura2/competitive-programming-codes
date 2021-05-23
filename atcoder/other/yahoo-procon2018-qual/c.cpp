#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),c(n),v(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&c[i]);
	rep(i,n) scanf("%lld",&v[i]);

	vector<lint> acum(n+1);
	rep(i,n) acum[i+1]=acum[i]+a[i];

	vector<lint> csum(1<<n),vsum(1<<n);
	rep(S,1<<n) rep(i,n) if(S>>i&1) {
		csum[S]+=c[i];
		vsum[S]+=v[i];
	}

	vector<lint> dp(1<<n);
	for(int S=1;S<(1<<n);S++){
		lint W=acum[popcount(S)];
		lint tmp=0;
		for(int T=(1<<n)-1;T>=0;T--){
			T&=~S;
			if(csum[T]<=W) tmp=max(tmp,vsum[T]);
		}

		lint tmp2=INF;
		rep(i,n) if(S>>i&1) {
			tmp2=min(tmp2,dp[S&~(1<<i)]);
		}

		dp[S]=max(tmp,tmp2);
	}

	printf("%lld\n",dp[(1<<n)-1]);

	return 0;
}
