#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int dp[3][100001]={};
	rep(i,n){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		dp[0][i+1]=max(dp[1][i],dp[2][i])+a;
		dp[1][i+1]=max(dp[0][i],dp[2][i])+b;
		dp[2][i+1]=max(dp[0][i],dp[1][i])+c;
	}
	printf("%d\n",max({dp[0][n],dp[1][n],dp[2][n]}));

	return 0;
}
