#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n); n++;
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int dp[11][11];
	rep(i,n){
		dp[i][0]=i+1;
		for(int j=1;j<=a[i];j++){
			dp[i][j]=INF;
			if(i>0 && j<=a[i-1]){
				dp[i][j]=dp[i-1][j]+1;
			}
			rep(k,j){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k-1]);
			}
		}
	}
	rep(j,a[n-1]+1) printf("%d%c",dp[n-1][j],j<a[n-1]?' ':'\n');

	return 0;
}
