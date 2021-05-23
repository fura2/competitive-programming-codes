// Day 1: Banner

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
	int h,w; scanf("%d%d",&h,&w);
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	lint ans=0;
	rep(i1,h) for(int i2=i1;i2<h;i2++) {
		int cnt[1<<4]={};
		rep(j,w){
			cnt[(1<<B[i1][j])|(1<<B[i2][j])]++;
		}
		rep(S1,1<<4) rep(S2,S1) if(popcount(S1|S2)>=3) ans+=cnt[S1]*cnt[S2];
	}
	printf("%lld\n",ans);

	return 0;
}
