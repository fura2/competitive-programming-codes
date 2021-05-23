#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int gx,gy,n,f; scanf("%d%d%d%d",&gx,&gy,&n,&f);
	vector<int> dx(n),dy(n),c(n);
	rep(i,n) scanf("%d%d%d",&dx[i],&dy[i],&c[i]);

	int dp[101][101];
	rep(y,gy+1) rep(x,gx+1) dp[y][x]=f*(x+y);
	rep(i,n){
		for(int y=gy;y>=dy[i];y--) for(int x=gx;x>=dx[i];x--) {
			dp[y][x]=min(dp[y][x],dp[y-dy[i]][x-dx[i]]+c[i]);
		}
	}
	printf("%d\n",dp[gy][gx]);

	return 0;
}
