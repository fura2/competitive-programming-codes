#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<vector<int>> A(n,vector<int>(n));
	rep(i,n) rep(j,n) scanf("%d",&A[i][j]);

	vector<vector<int>> sum(n+1,vector<int>(n));
	rep(i,n) rep(j,n) sum[i+1][j]=sum[i][j]+A[i][j];

	// dp[i][j] := ( i 匹目まで見て, 猫 i とマッチする一番左の猫が猫 j であるときの最大価値 )
	// 可能な猫の配置は行列 A の右上三角の部分をジグザグに降りていくパスに対応する, と考えるとわかりやすい
	vector<vector<int>> dp(n,vector<int>(n));
	for(int i=1;i<n;i++){
		int tmp=-INF;
		rep(j,i){
			tmp=max(tmp,dp[i-1][j]);
			dp[i][j]=tmp+sum[i][i]-sum[j][i];
		}
		dp[i][i]=tmp;
	}
	printf("%d\n",*max_element(dp[n-1].begin(),dp[n-1].end())*2);

	return 0;
}
