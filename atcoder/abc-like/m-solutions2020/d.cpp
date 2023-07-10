#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<lint> dp(n);
	dp[0]=1000;
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1];
		rep(j,i) if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]%a[j]+dp[j]/a[j]*a[i]);
	}
	printf("%lld\n",dp[n-1]);

	return 0;
}
