#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int h,w,n; scanf("%d%d%d",&w,&h,&n);
	bool B[16][16]={};
	rep(i,n){
		int y,x; scanf("%d%d",&x,&y); y--; x--;
		B[y][x]=true;
	}

	lint dp[16][16]={};
	dp[0][0]=1;
	rep(i,h) rep(j,w) {
		if(B[i][j]) dp[i][j]=0;
		if(i<h-1) dp[i+1][j]+=dp[i][j];
		if(j<w-1) dp[i][j+1]+=dp[i][j];
	}
	printf("%lld\n",dp[h-1][w-1]);

	return 0;
}
