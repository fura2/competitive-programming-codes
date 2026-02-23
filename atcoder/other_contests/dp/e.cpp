#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1e9+1;

int main(){
	int n,W,w[100],v[100];
	scanf("%d%d",&n,&W);
	rep(i,n) scanf("%d%d",&w[i],&v[i]);

	int dp[100001];
	rep(a,1e5+1) dp[a]=INF;
	dp[0]=0;
	rep(i,n) for(int a=1e5;a>=v[i];a--) dp[a]=min(dp[a],dp[a-v[i]]+w[i]);

	int ans=0;
	rep(a,1e5+1) if(dp[a]<=W) ans=a;
	printf("%d\n",ans);

	return 0;
}
