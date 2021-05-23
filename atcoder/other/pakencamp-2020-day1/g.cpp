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
	vector<int> l(m),r(m),x(m);
	rep(i,m) scanf("%d%d%d",&l[i],&r[i],&x[i]), l[i]--;

	int ans=-1;
	rep(S,1<<n){
		bool ok=true;
		rep(j,m){
			int cnt=0;
			for(int i=l[j];i<r[j];i++) if(S>>i&1) cnt++;
			if(cnt!=x[j]) ok=false;
		}
		if(ok) ans=max(ans,popcount(S));
	}
	printf("%d\n",ans);

	return 0;
}
