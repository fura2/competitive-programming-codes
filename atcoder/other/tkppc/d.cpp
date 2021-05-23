#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,h,w; scanf("%d%d%d",&n,&h,&w);
	char B[100][100][101];
	rep(i,n) rep(x,h) scanf("%s",B[i][x]);

	int dp[100][100][100];
	rep(i,n) rep(x,h) rep(y,w) dp[i][x][y]=INF;
	dp[0][0][0]=0;
	rep(i,n) rep(x,h) rep(y,w) {
		int cost=(B[i][x][y]=='H'?0:B[i][x][y]-'0');
		if(i>0 && B[i-1][x][y]=='H') dp[i][x][y]=min(dp[i][x][y],dp[i-1][x][y]+cost);
		if(x>0 && B[i][x-1][y]!='H') dp[i][x][y]=min(dp[i][x][y],dp[i][x-1][y]+cost);
		if(y>0 && B[i][x][y-1]!='H') dp[i][x][y]=min(dp[i][x][y],dp[i][x][y-1]+cost);
	}
	printf("%d\n",dp[n-1][h-1][w-1]);

	return 0;
}
