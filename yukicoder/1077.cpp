#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	static int dp[1000][10001];
	rep(i,n) rep(j,10001) dp[i][j]=INF;
	rep(j,10001) dp[0][j]=abs(a[0]-j);
	rep(i,n-1){
		int mn=INF;
		rep(j,10001){
			mn=min(mn,dp[i][j]);
			dp[i+1][j]=min(dp[i+1][j],mn+abs(a[i+1]-j));
		}
	}
	printf("%d\n",*min_element(dp[n-1],dp[n-1]+10001));

	return 0;
}
