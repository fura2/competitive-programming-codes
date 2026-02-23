#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n;
	string s; cin>>n>>s;

	vector<int> dp(n,INF);
	dp[0]=0;
	rep(i,n){
		if(i+1<n) dp[i+1]=min(dp[i+1],dp[i]+(s[i+1]=='.'?0:1));
		if(i+2<n) dp[i+2]=min(dp[i+2],dp[i]+(s[i+2]=='.'?0:1));
		if(i+3<n) dp[i+3]=min(dp[i+3],dp[i]+(s[i+3]=='.'?0:1));
	}
	printf("%d\n",dp[n-1]);

	return 0;
}
