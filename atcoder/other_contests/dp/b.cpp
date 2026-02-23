#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1e9+1;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> c(n);
	rep(i,n) scanf("%d",&c[i]);

	vector<int> dp(n,INF);
	dp[0]=0;
	rep(i,n) for(int d=1;d<=k;d++) if(i+d<n) dp[i+d]=min(dp[i+d],dp[i]+abs(c[i+d]-c[i]));
	printf("%d\n",dp[n-1]);

	return 0;
}
