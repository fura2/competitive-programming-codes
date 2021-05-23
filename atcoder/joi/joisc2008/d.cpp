// Day 2: Nile.Com

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,d; scanf("%d%d",&n,&d);
	vector a(d,vector(n,0));
	rep(i,d) rep(j,n) scanf("%d",&a[i][j]);

	vector dp(d,vector(2*n,INF));
	rep(j,n) dp[0][j]=a[0][j];
	for(int i=1;i<d;i++){
		int mn=*min_element(dp[i-1].begin(),dp[i-1].end());
		rep(j,n){
			dp[i][j]=mn+a[i][j];
			dp[i][j+n]=min(dp[i-1][j]+a[i][j]/10*9,dp[i-1][j+n]+a[i][j]/10*7);
		}
	}
	printf("%d\n",*min_element(dp[d-1].begin(),dp[d-1].end()));

	return 0;
}
