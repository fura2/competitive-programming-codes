#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int f[128];
	f['B']=0; f['R']=1; f['W']=2;

	int n; cin>>n;
	string B[5];
	rep(i,5) cin>>B[i];

	int cnt[3][999];
	rep(c,3) rep(j,n) cnt[c][j]=5;
	rep(i,5) rep(j,n) if(B[i][j]!='#') cnt[f[B[i][j]]][j]--;

	int dp[3][999];
	rep(c,3) dp[c][0]=cnt[c][0];
	rep(j,n-1) rep(c,3) {
		dp[c][j+1]=INF;
		rep(pre,3) if(pre!=c) dp[c][j+1]=min(dp[c][j+1],dp[pre][j]+cnt[c][j+1]);
	}
	cout<<min({dp[0][n-1],dp[1][n-1],dp[2][n-1]})<<'\n';

	return 0;
}
