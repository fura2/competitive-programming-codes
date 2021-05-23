#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	if(m==0) return puts("0"),0;

	// 頂点 0 を選ばない
	static int dp1[3000][3001][2];
	rep(i,n) rep(j,m+1) rep(k,2) dp1[i][j][k]=-INF;
	dp1[0][0][0]=0;
	for(int i=1;i<n;i++){
		rep(j,m+1){
			// 頂点 i を選ばない
			dp1[i][j][0]=max(dp1[i-1][j][0],dp1[i-1][j][1]);
			// 頂点 i を選ぶ
			if(j<m) dp1[i][j+1][1]=max(dp1[i-1][j][0],dp1[i-1][j][1]+a[i-1]);
		}
	}

	// 頂点 0 を選ぶ
	static int dp2[3000][3001][2];
	rep(i,n) rep(j,m+1) rep(k,2) dp2[i][j][k]=-INF;
	dp2[0][1][1]=0;
	for(int i=1;i<n;i++){
		rep(j,m+1){
			// 頂点 i を選ばない
			dp2[i][j][0]=max(dp2[i-1][j][0],dp2[i-1][j][1]);
			// 頂点 i を選ぶ
			if(j<m) dp2[i][j+1][1]=max(dp2[i-1][j][0],dp2[i-1][j][1]+a[i-1])+(i==n-1?a[n-1]:0);
		}
	}

	printf("%d\n",max({dp1[n-1][m][0],dp1[n-1][m][1],dp2[n-1][m][0],dp2[n-1][m][1]}));

	return 0;
}
