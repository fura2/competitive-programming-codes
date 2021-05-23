#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> c(n);
	rep(i,n) scanf("%d",&c[i]);

	vector<int> dp(n);
	dp[1]=abs(c[1]-c[0]);
	for(int i=2;i<n;i++) dp[i]=min(dp[i-1]+abs(c[i]-c[i-1]),dp[i-2]+abs(c[i]-c[i-2]));
	printf("%d\n",dp[n-1]);

	return 0;
}
