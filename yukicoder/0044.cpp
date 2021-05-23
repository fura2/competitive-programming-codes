#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	lint dp[51]={1,1};
	for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
	printf("%lld\n",dp[n]);
	return 0;
}
