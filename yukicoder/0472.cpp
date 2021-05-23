#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	int dp[2][15001];
	rep(j,m+1) dp[0][j]=(j==m?0:INF);
	rep(i,n){
		int a[4];
		rep(k,3) scanf("%d",&a[k]);
		a[3]=1;

		int curr=i%2,next=(i+1)%2;
		rep(j,m+1) dp[next][j]=INF;
		rep(j,m+1) rep(k,4) if(j>=k) dp[next][j-k]=min(dp[next][j-k],dp[curr][j]+a[k]);
		rep(j,m+1) dp[curr][j]=dp[next][j];
	}

	printf("%.9f\n",1.0**min_element(dp[n%2],dp[n%2]+m+1)/n);

	return 0;
}
