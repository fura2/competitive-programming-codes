#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int n,a,b;
int val[13],vsum[1<<13];

lint memo[1<<13];

lint dfs(int S){
	lint& res=memo[S];
	if(res!=-1) return res;

	if(popcount(S)>=n-1) return res=1;

	res=0;
	rep(r,n) if(~S>>r&1) { // 根
		int S2=S|(1<<r);
		for(int T=(1<<n)-1;T>=0;T--){ // 左の部分木の頂点集合
			T&=~S2;
			int diff=abs(vsum[T]-vsum[((1<<n)-1)&~S2&~T]);
			if(a<=diff && diff<=b){
				res+=dfs(((1<<n)-1)&~T)*dfs(S2|T);
			}
		}
	}
	return res;
}

int main(){
	while(1){
		scanf("%d%d%d",&n,&a,&b);
		if(n==0 && a==0 && b==0) break;
		rep(u,n) scanf("%d",&val[u]);

		rep(S,1<<n){
			vsum[S]=0;
			rep(u,n) if(S>>u&1) vsum[S]+=val[u];
		}

		rep(S,1<<n) memo[S]=-1;
		printf("%lld\n",dfs(0));
	}

	return 0;
}
