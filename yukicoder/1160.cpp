#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> p(n),a(n);
	rep(i,n) scanf("%d%d",&p[i],&a[i]);

	vector dp(n+1,vector(2,-INF));
	dp[0][0]=0;
	rep(i,n){
		dp[i+1][0]=max(dp[i][0],dp[i][1]+p[i])+p[i];
		dp[i+1][1]=max(dp[i][0],dp[i][1]+a[i])+a[i];
	}
	printf("%d\n",max(dp[n][0],dp[n][1]));

	return 0;
}
