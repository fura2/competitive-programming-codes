#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector dp(n,vector(21,0LL));
	dp[0][0]=1;
	rep(i,n-1) rep(x,21) {
		if(0<=x+a[i] && x+a[i]<=20){
			dp[i+1][x+a[i]]+=dp[i][x];
		}
		if(i>0 && 0<=x-a[i] && x-a[i]<=20){
			dp[i+1][x-a[i]]+=dp[i][x];
		}
	}
	printf("%lld\n",dp[n-1][a[n-1]]);

	return 0;
}
