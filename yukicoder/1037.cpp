#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,V,L; scanf("%d%d%d",&n,&V,&L);
	vector<int> x(n+2),v(n+2),w(n+2);
	rep(i,n) scanf("%d%d%d",&x[i+1],&v[i+1],&w[i+1]);
	x[n+1]=L;

	// dp[i][j] = ( i 番目のガソリンスタンドまで行って, 残りガソリンが j リットルあるときの最小コスト)
	static lint dp[2002][2001];
	rep(i,n+2) rep(j,V+1) dp[i][j]=INF;
	dp[0][V]=0;
	rep(i,n+1){
		int j0=x[i+1]-x[i];
		for(int j=j0;j<=V;j++){
			// 補充しない
			dp[i+1][j-j0]=min(dp[i+1][j-j0],dp[i][j]);
			// 補充する
			int j2=min(j-j0+v[i+1],V);
			dp[i+1][j2]=min(dp[i+1][j2],dp[i][j]+w[i+1]);
		}
	}

	lint ans=*min_element(dp[n+1],dp[n+1]+V+1);
	printf("%lld\n",ans<INF?ans:-1);

	return 0;
}
