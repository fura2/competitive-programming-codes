#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	double r[1024];
	rep(i,1<<n) scanf("%lf",r+i);

	double dp[11][1024]={}; // dp[i][j] := ( i 回戦が終わったとき j 番目の人が勝ち残っている確率 )
	rep(j,1<<n) dp[0][j]=1;
	rep(i,n) rep(j,1<<n) {
		int k=(j&~((1<<i)-1))^(1<<i);
		rep(l,1<<i){
			double p=1/(1+pow(10,(r[k+l]-r[j])/400));
			dp[i+1][j]+=dp[i][j]*dp[i][k+l]*p;
		}
	}
	rep(i,1<<n) printf("%.9f\n",dp[n][i]);

	return 0;
}
