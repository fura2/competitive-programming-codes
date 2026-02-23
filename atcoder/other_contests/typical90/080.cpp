#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(unsigned long long x){
	x-=(x>>1)&0x5555555555555555LL;
	x=(x&0x3333333333333333LL)+((x>>2)&0x3333333333333333LL);
	x=(x+(x>>4))&0x0f0f0f0f0f0f0f0fLL;
	x=(x*0x0101010101010101LL)>>56;
	return x;
}

int main(){
	int n,d; scanf("%d%d",&n,&d);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint ans=0;
	rep(S,1<<n){
		lint x=0;
		rep(i,n) if(S>>i&1) x|=a[i];
		int sgn=(popcount(S)%2==0?1:-1);
		ans+=sgn*(1LL<<(d-popcount(x)));
	}
	printf("%lld\n",ans);

	return 0;
}
