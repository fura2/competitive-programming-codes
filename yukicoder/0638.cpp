#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(long long x){
	x-=(x>>1)&0x5555555555555555LL;
	x=(x&0x3333333333333333LL)+((x>>2)&0x3333333333333333LL);
	x=(x+(x>>4))&0x0f0f0f0f0f0f0f0fLL;
	x=(x*0x0101010101010101LL)>>56;
	return x;
}

int main(){
	lint n; scanf("%lld",&n);

	lint a;
	for(a=1;a<n;a++) if(popcount(a)>1 && popcount(n-a)>1) break;
	if(a==n) puts("-1");
	else printf("%lld %lld\n",a,n-a);

	return 0;
}
