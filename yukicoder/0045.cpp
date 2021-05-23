#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int dp[1002]={};
	rep(i,n){
		int a; scanf("%d",&a);
		rep(j,i+1) dp[i+2]=max(dp[i+2],dp[j]+a);
	}
	printf("%d\n",*max_element(dp,dp+n+2));

	return 0;
}
