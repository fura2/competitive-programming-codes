#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline int popcount(unsigned long long x){
	x-=(x>>1)&0x5555555555555555LL;
	x=(x&0x3333333333333333LL)+((x>>2)&0x3333333333333333LL);
	x=(x+(x>>4))&0x0f0f0f0f0f0f0f0fLL;
	x=(x*0x0101010101010101LL)>>56;
	return x;
}

int main(){
	int m,n; scanf("%d%d%*d",&m,&n);

	unsigned long long A[1600]={},B[1600]={};
	rep(i,m){ int a; scanf("%d",&a); A[a/64]|=1ULL<<a%64; }
	rep(i,n){ int b; scanf("%d",&b); B[b/64]|=1ULL<<b%64; }

	int q; scanf("%d",&q);
	rep(i,q){
		int d1=i/64,d2=i%64;
		int ans=0;
		for(int x=d1;x<1600;x++){
			auto b=B[x-d1]<<d2;
			if(x>d1 && d2>0) b|=B[x-d1-1]>>(64-d2);
			ans+=popcount(A[x]&b);
		}
		printf("%d\n",ans);
	}

	return 0;
}
