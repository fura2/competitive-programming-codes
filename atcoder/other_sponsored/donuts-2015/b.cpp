#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);
	vector<int> b(m),c(m);
	rep(i,m){
		int k; scanf("%d%d",&b[i],&k);
		rep(j,k){
			int id; scanf("%d",&id); id--;
			c[i]|=1<<id;
		}
	}

	int ans=0;
	rep(S,1<<n) if(popcount(S)==9) {
		int tmp=0;
		rep(i,n) if(S>>i&1) tmp+=a[i];
		rep(i,m) if(popcount(S&c[i])>=3) tmp+=b[i];
		ans=max(ans,tmp);
	}
	printf("%d\n",ans);

	return 0;
}
