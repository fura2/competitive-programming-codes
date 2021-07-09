#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

inline int popcount(unsigned int x){
	x-=(x>>1)&0x55555555;
	x=(x&0x33333333)+((x>>2)&0x33333333);
	return ((x+(x>>4)&0x0f0f0f0f)*0x01010101)>>24;
}

int main(){
	vector dp(1<<16,vector(500,0LL));
	const int offset=250;
	dp[0][offset]=1;
	rep(S,1<<16){
		int val=popcount(S)+1;
		for(int score=-offset;score<offset;score++){
			if(dp[S][score+offset]==0) continue;

			rep(i,4) rep(j,4) if(~S>>(i*4+j)&1) {
				int score2=score;
				rep(k,4){
					int x=i+dx[k],y=j+dy[k];
					if(0<=x && x<4 && 0<=y && y<4){
						if(S>>(x*4+y)&1) score2+=val;
						else             score2-=val;
					}
				}
				dp[S|1<<(i*4+j)][score2+offset]+=dp[S][score+offset];
			}
		}
	}

	int tar; scanf("%d",&tar);
	printf("%lld\n",dp[(1<<16)-1][tar+offset]);

	return 0;
}
