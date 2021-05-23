#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	double p[3000];
	rep(i,n) scanf("%lf",&p[i]);

	double dp[2][3001]={};
	dp[0][0]=1;
	int curr=0,next=1;
	rep(i,n){
		rep(j,n+1) dp[next][j]=0;

		rep(j,i+1){
			dp[next][j+1]+=p[i]*dp[curr][j];
			dp[next][j]+=(1-p[i])*dp[curr][j];
		}

		rep(j,n+1) dp[curr][j]=dp[next][j];
		swap(curr,next);
	}

	double ans=0;
	rep(j,n+1) if(j>n-j) ans+=dp[curr][j];
	printf("%.15f\n",ans);

	return 0;
}
