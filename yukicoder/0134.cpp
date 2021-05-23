#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double INF=1e77;

int main(){
	double x0,y0;
	int n; scanf("%lf%lf%d",&x0,&y0,&n);
	vector<double> x(n+1),y(n+1),w(n+1);
	rep(i,n) scanf("%lf%lf%lf",&x[i],&y[i],&w[i]);
	x[n]=x0;
	y[n]=y0;
	n++;

	double d[14][14];
	rep(i,n) rep(j,n) d[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);

	double dp[1<<14][14];
	rep(S,1<<n) rep(i,n) dp[S][i]=INF;
	dp[1<<(n-1)][n-1]=0;
	rep(S,1<<n){
		double wsum=0;
		rep(i,n) if((S>>i&1)==0) wsum+=w[i];
		rep(i,n) if(S>>i&1) {
			rep(j,n) if((S>>j&1)==0) {
				dp[S|1<<j][j]=min(dp[S|1<<j][j],dp[S][i]+d[i][j]*(wsum+100)/120+w[j]);
			}
		}
	}

	double ans=INF;
	rep(i,n) ans=min(ans,dp[(1<<n)-1][i]+d[i][n-1]*100/120);
	printf("%.9f\n",ans);

	return 0;
}
