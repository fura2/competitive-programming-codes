#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,W,w[100],v[100];
	scanf("%d%d",&n,&W);
	rep(i,n) scanf("%d%d",&w[i],&v[i]);

	lint dp[100001]={};
	rep(i,n) for(int a=W;a>=w[i];a--) dp[a]=max(dp[a],dp[a-w[i]]+v[i]);

	printf("%lld\n",*max_element(dp,dp+100001));

	return 0;
}
