#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m; scanf("%d",&m);
	int n=1<<m;
	vector<double> a(n);
	rep(i,n) scanf("%lf",&a[i]), a[i]*=a[i];

	// dp[i][j] = 人 j が i 回戦後に残っている確率
	vector<vector<double>> dp(m+1,vector<double>(n));
	rep(j,n) dp[0][j]=1;
	rep(i,m) rep(j,n) {
		rep(k,n) if(j!=k) {
			int t;
			for(t=m-1;(j>>t&1)==(k>>t&1);t--);
			if(t==i){
				dp[i+1][j]+=dp[i][j]*dp[i][k]*a[j]/(a[j]+a[k]);
			}
		}
	}
	printf("%.9f\n",dp[m][0]);

	return 0;
}
