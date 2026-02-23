#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	vector<int> dp(2*n+1);
	for(int i=2;i<=2*n;i++){
		dp[i]=dp[i-1];
		if(s[i-2]!=s[i-1]) dp[i]=max(dp[i],dp[i-2]+1);
	}
	printf("%d\n",n-dp[2*n]);

	return 0;
}
