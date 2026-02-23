#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m);
	rep(i,m) scanf("%d",&a[i]);

	vector cnt(n,vector(n,0LL)); // cnt[x][y] = (a[i]=x, a[j]=y, i<j なるペア (x,y) の個数)
	{
		vector tmp(n,0LL);
		rep(i,m){
			rep(x,n) cnt[x][a[i]]+=tmp[x];
			tmp[a[i]]++;
		}
	}

	vector dp(1<<n,INF);
	dp[0]=0;
	rep(S,1<<n) if(dp[S]<INF) {
		rep(i,n) if(~S>>i&1) {
			lint cost=0;
			rep(x,n) if(x!=i && ~S>>x&1) cost+=cnt[x][i];
			dp[S|1<<i]=min(dp[S|1<<i],dp[S]+cost);
		}
	}
	printf("%lld\n",dp[(1<<n)-1]);

	return 0;
}
