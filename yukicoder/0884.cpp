#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	string s; cin>>s;
	int n=s.length();

	reverse(s.begin(),s.end());

	// dp[i+1][c] = (2^0, ..., 2^i の位を 0 にして, 2^{i+1} へのキャリーが c であるときの最小コスト)
	vector dp(n+1,vector(2,INF));
	dp[0][0]=0;
	rep(i,n){
		if(s[i]=='0'){
			dp[i+1][0]=min(dp[i+1][0],dp[i][0]);   // nop
			dp[i+1][0]=min(dp[i+1][0],dp[i][1]+1); // -2^i
			dp[i+1][1]=min(dp[i+1][1],dp[i][1]+1); // +2^i
		}
		else{
			dp[i+1][0]=min(dp[i+1][0],dp[i][0]+1); // -2^i
			dp[i+1][1]=min(dp[i+1][1],dp[i][0]+1); // +2^i
			dp[i+1][1]=min(dp[i+1][1],dp[i][1]);   // nop
		}
	}

	printf("%d\n",min(dp[n][0],dp[n][1]+1));

	return 0;
}
