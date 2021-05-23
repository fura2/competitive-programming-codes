#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> w(n);
	rep(i,n) scanf("%d",&w[i]);

	int sum=accumulate(w.begin(),w.end(),0);
	if(sum%2!=0) return puts("impossible"),0;

	vector<bool> dp(5e3+1);
	dp[0]=true;
	rep(i,n) for(int a=sum/2;a>=w[i];a--) if(dp[a-w[i]]) dp[a]=true;
	puts(dp[sum/2]?"possible":"impossible");

	return 0;
}
