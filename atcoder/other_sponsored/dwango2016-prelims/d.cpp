#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

lint solve(vector<vector<lint>> a){
	int h=a.size(),w=a[0].size();

	vector cum(h+1,vector(w+1,0LL));
	rep(i,h) rep(j,w) cum[i+1][j+1]=cum[i+1][j]+cum[i][j+1]-cum[i][j]+a[i][j];

	vector dp1(w,-INF);
	vector dp2(w,-INF);
	rep(t,h) for(int b=t+1;b<=h;b++) {
		vector<lint> val(w);
		rep(j,w) val[j]=cum[b][j+1]-cum[t][j+1]-cum[b][j]+cum[t][j];

		vector<lint> dp(w);
		dp[0]=val[0];
		rep(j,w-1) dp[j+1]=max(dp[j],0LL)+val[j+1];
		rep(j,w-1) dp[j+1]=max(dp[j+1],dp[j]);

		rep(j,w) dp1[j]=max(dp1[j],dp[j]);

		dp[w-1]=val[w-1];
		for(int j=w-1;j>0;j--) dp[j-1]=max(dp[j],0LL)+val[j-1];
		for(int j=w-1;j>0;j--) dp[j-1]=max(dp[j-1],dp[j]);

		rep(j,w) dp2[j]=max(dp2[j],dp[j]);
	}

	lint res=-INF;
	rep(j,w-1) res=max(res,dp1[j]+dp2[j+1]);
	return res;
}

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector a1(h,vector(w,0LL));
	vector a2(w,vector(h,0LL));
	rep(i,h) rep(j,w) {
		scanf("%lld",&a1[i][j]);
		a2[j][i]=a1[i][j];
	}

	printf("%lld\n",max(solve(a1),solve(a2)));

	return 0;
}
