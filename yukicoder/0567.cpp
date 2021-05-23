#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	static double dp[1000001][7];
	dp[0][0]=1;
	rep(i,n){
		rep(j,7){
			dp[i+1][j]+=dp[i][j]*j/6;
			if(j<6){
				dp[i+1][j+1]+=dp[i][j]*(6-j)/6;
			}
		}
	}
	printf("%.9f\n",dp[n][6]);

	return 0;
}
