#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n-1);
	rep(i,n-1) scanf("%d",&a[i]);

	// dp[i][j] = (左から i+1 マスについて, i+1 マス目を含む j マスのまとまりを作るための最小コスト)
	vector dp(2,vector(n+1,INF));
	dp[0][1]=0;
	for(int i=1;i<n;i++){
		int curr=i%2,prev=(i+1)%2;
		rep(j,n+1) dp[curr][j]=INF;

		for(int j=1;j<=i+1;j++){
			// a[i-1] で切る
			dp[curr][j]=a[i-1]+min(dp[prev][j-1],dp[prev][i-j+1]);
			// a[i-1] で切らない
			dp[curr][j]=min(dp[curr][j],dp[prev][j-1]);
		}
	}
	printf("%d\n",dp[(n-1)%2][n/2]);

	return 0;
}
