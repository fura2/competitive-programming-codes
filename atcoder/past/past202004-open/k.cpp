#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n;
	string s; cin>>n>>s;
	vector<lint> cost1(n),cost2(n);
	rep(i,n) scanf("%lld",&cost1[i]);
	rep(i,n) scanf("%lld",&cost2[i]);

	static lint dp[3001][3001];
	rep(i,n+1) rep(j,n+1) dp[i][j]=INF;
	dp[0][0]=0;
	rep(i,n){
		rep(j,i+1){
			// (
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(s[i]=='('?0:cost1[i]));
			// )
			if(j>0) dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+(s[i]==')'?0:cost1[i]));
			// delete
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+cost2[i]);
		}
	}
	printf("%lld\n",dp[n][0]);

	return 0;
}
