#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	if(n==2) return printf("%lld\n",a[1]-a[0]),0;
	if(n==3) return printf("%lld\n",a[2]-a[0]),0;

	vector<lint> dp(n);
	dp[0]=INF;
	dp[1]=a[1]-a[0];
	dp[2]=a[2]-a[0];
	for(int i=3;i<n;i++){
		dp[i]=min(dp[i-2]+a[i]-a[i-1],dp[i-3]+a[i]-a[i-2]);
	}
	printf("%lld\n",dp[n-1]);

	return 0;
}
