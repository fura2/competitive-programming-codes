#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const double INF=1e77;

int main(){
	int n,k;
	lint a0; scanf("%d%d%lld",&n,&k,&a0);
	vector<lint> a(n),b(n);
	vector<int> c(n),d(n);
	rep(i,n) scanf("%lld%lld%d%d",&a[i],&b[i],&c[i],&d[i]);

	double lo=0,hi=1e13;
	rep(_,60){
		double mi=(lo+hi)/2;

		vector dp(2,vector(k+1,-INF));
		dp[0][k]=a0-mi;
		rep(i,n) dp[0][k]+=a[i]-mi;
		rep(i,n){
			rep(j,k+1) dp[1][j]=-INF;

			// 退部
			for(int j=k;j>=d[i];j--) dp[1][j-d[i]]=max(dp[1][j-d[i]],dp[0][j]+mi-a[i]);
			// 教育
			for(int j=k;j>=c[i];j--) dp[0][j-c[i]]=max(dp[0][j-c[i]],dp[0][j]+b[i]);
			rep(j,k+1) dp[1][j]=max(dp[1][j],dp[0][j]);

			swap(dp[0],dp[1]);
		}

		if(*max_element(dp[0].begin(),dp[0].end())>0) lo=mi; else hi=mi;
	}
	printf("%.9f\n",lo);

	return 0;
}
