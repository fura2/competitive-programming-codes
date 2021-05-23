#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	vector a(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&a[i][j]);

	vector dp(h,vector(w,0));
	dp[0][0]=n-1;
	rep(i,h) rep(j,w) {
		if(i+1<h) dp[i+1][j]+=(dp[i][j]+1-a[i][j])/2;
		if(j+1<w) dp[i][j+1]+=(dp[i][j]+a[i][j])/2;
	}

	rep(i,h) rep(j,w) a[i][j]=(a[i][j]+dp[i][j])%2;

	int y=0,x=0;
	while(y<h && x<w){
		if(a[y][x]==0) y++;
		else           x++;
	}
	printf("%d %d\n",y+1,x+1);

	return 0;
}
