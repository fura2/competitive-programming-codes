#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> dp(n+1);
	dp[1]=1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]) dp[i+1]=dp[i]+1;
		else dp[i+1]=max(dp[i],dp[i-1]+1);
	}
	printf("%d\n",dp[n]);

	return 0;
}
