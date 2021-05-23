#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int MOD,r; scanf("%d%d",&MOD,&r);

	vector<int> next[10];
	next[0]={1};
	next[1]={0,2,4};
	next[2]={1,3,5};
	next[3]={2,6};
	next[4]={1,5,7};
	next[5]={2,4,6,8};
	next[6]={3,5,9};
	next[7]={4,8};
	next[8]={5,7,9};
	next[9]={6,8};

	int dp[10][100000];
	rep(pos,10) rep(a,MOD) dp[pos][a]=INF;
	dp[0][0]=0;
	rep(_,30){
		rep(pos,10) rep(a,MOD) {
			dp[pos][(a*10+pos)%MOD]=min(dp[pos][(a*10+pos)%MOD],dp[pos][a]+1);
			for(int pos2:next[pos]){
				dp[pos2][a]=min(dp[pos2][a],dp[pos][a]+1);
			}
		}
	}

	int ans=INF;
	rep(pos,10) ans=min(ans,dp[pos][r]);
	printf("%d\n",ans);

	return 0;
}
