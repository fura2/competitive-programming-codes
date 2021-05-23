#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> dp(n+1,INF);
	dp[0]=0;
	rep(i,n){
		lint mx=-INF,mn=INF;
		for(int d=1;d<=m;d++){
			if(i+1-d<0) break;
			mx=max(mx,a[i+1-d]);
			mn=min(mn,a[i+1-d]);
			dp[i+1]=min(dp[i+1],dp[i+1-d]+k+d*(mx-mn));
		}
	}
	printf("%lld\n",dp[n]);

	return 0;
}
