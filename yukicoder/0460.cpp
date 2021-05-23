#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	int h,w; scanf("%d%d",&h,&w);
	int B[8]={};
	rep(i,h) rep(j,w) {
		int a; scanf("%d",&a);
		B[i]|=a<<j;
	}

	vector<int> cost(1<<w,INF);
	rep(S,1<<w){
		int pttn={};
		rep(j,w) if(S>>j&1) {
			if(j> 0 ) pttn^=1<<(j-1);
			pttn^=1<<j;
			if(j<w-1) pttn^=1<<(j+1);
		}
		cost[pttn]=min(cost[pttn],popcount(S));
	}

	if(h==1){
		if(cost[B[0]]<INF) printf("%d\n",cost[B[0]]);
		else               puts("Impossible");
		return 0;
	}

	static int dp[8][1<<8][1<<8];
	rep(i,h) rep(S,1<<w) rep(T,1<<w) dp[i][S][T]=INF;
	rep(S,1<<w) dp[0][B[0]^S][B[1]^S]=cost[S];
	for(int i=1;i<h-1;i++){
		rep(S,1<<w) rep(T,1<<w) {
			dp[i][T^S][B[i+1]^S]=min(dp[i][T^S][B[i+1]^S],dp[i-1][S][T]+cost[S]);
		}
	}

	int ans=INF;
	rep(S,1<<w) ans=min(ans,dp[h-2][S][S]+cost[S]);
	if(ans<INF) printf("%d\n",ans);
	else        puts("Impossible");

	return 0;
}
