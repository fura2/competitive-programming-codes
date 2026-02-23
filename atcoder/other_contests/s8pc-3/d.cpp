#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int h,w,a[200][200]; scanf("%d%d",&h,&w);
	rep(i,h) rep(j,w) scanf("%d",&a[i][j]);

	static int dp[201][200][200];
	rep(i,h+1) rep(j1,w) rep(j2,w) dp[i][j1][j2]=-INF;
	dp[0][0][0]=0;
	rep(i,h){
		// 1 行下に降りる
		rep(j1,w) for(int j2=j1;j2<w;j2++) if(dp[i][j1][j2]!=-INF) {
			int val;
			if(j1<j2) val=a[i][j1]+a[i][j2];
			else      val=a[i][j1];
			dp[i+1][j1][j2]=dp[i][j1][j2]+val;
		}

		// 左の人を動かす
		rep(j2,w){
			rep(j1,j2-1) if(dp[i+1][j1][j2]!=-INF) {
				dp[i+1][j1+1][j2]=max(dp[i+1][j1+1][j2],dp[i+1][j1][j2]+a[i][j1+1]);
			}
		}

		// 右の人を動かす
		rep(j1,w){
			for(int j2=j1;j2<w-1;j2++) if(dp[i+1][j1][j2]!=-INF) {
				dp[i+1][j1][j2+1]=max(dp[i+1][j1][j2+1],dp[i+1][j1][j2]+a[i][j2+1]);
			}
		}
	}

	int ans=-INF;
	rep(j1,w) ans=max(ans,dp[h][j1][w-1]);
	printf("%d\n",ans);

	return 0;
}
