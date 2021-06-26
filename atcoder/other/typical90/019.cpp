#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	n*=2;
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector dp(n,vector(n+1,INF));
	rep(l,n) dp[l][l]=0;
	for(int w=2;w<=n;w+=2){
		rep(l,n-w+1){
			int r=l+w;
			dp[l][r]=min(dp[l][r],dp[l+1][r-1]+abs(a[l]-a[r-1]));
			for(int c=l+1;c<r;c++){
				dp[l][r]=min(dp[l][r],dp[l][c]+dp[c][r]);
			}
		}
	}
	printf("%d\n",dp[0][n]);

	return 0;
}
