#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; cin>>n;

	// answer is [x^{6n}](1+x+...+x^n)^8
	lint dp[601]={1};
	rep(_,8){
		for(int i=6*n;i>=n+1;i--) dp[i]-=dp[i-(n+1)];
		rep(i,6*n) dp[i+1]+=dp[i];
	}
	cout<<dp[6*n]<<'\n';

	return 0;
}
