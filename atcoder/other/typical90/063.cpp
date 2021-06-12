#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int h,w; cin>>h>>w;
	vector B(h,vector<int>(w));
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	int ans=0;
	rep(S,1<<h) if(S!=0) {
		map<int,int> f;
		rep(j,w){
			bool ok=true;
			int pre=-1;
			rep(i,h) if(S>>i&1) {
				if(pre==-1 || B[i][j]==pre){
					pre=B[i][j];
				}
				else{
					ok=false;
					break;
				}
			}
			if(ok) ++f[pre];
		}
		int mx=0;
		for(auto [_,cnt]:f) mx=max(mx,cnt);
		ans=max(ans,popcount(S)*mx);
	}
	printf("%d\n",ans);

	return 0;
}
