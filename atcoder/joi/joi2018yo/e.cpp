#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector a(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&a[i][j]);

	vector dp(h*w+1,vector(h,vector(w,INF)));
	dp[0][0][0]=0;
	rep(d,h*w){
		rep(i,h) rep(j,w) if(dp[d][i][j]<INF) {
			rep(k,4){
				int x=i+dx[k],y=j+dy[k];
				if(0<=x && x<h && 0<=y && y<w){
					dp[d+1][x][y]=min(dp[d+1][x][y],dp[d][i][j]+(2*d+1)*a[x][y]);
				}
			}
		}
	}

	int ans=INF;
	rep(d,h*w+1) ans=min(ans,dp[d][h-1][w-1]);
	printf("%d\n",ans);

	return 0;
}
