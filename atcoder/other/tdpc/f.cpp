#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1e9+7;

int main(){
	int n,k; cin>>n>>k; n--;

	// naive O(nk) DP
	// dp[i][j] = ( 駅 i まで考えたとき, 駅 i に止まり, それが j 連続目だったときの場合の数 )
	/*
	int dp[1001][1000]={};
	dp[0][1]=1;
	rep(i,n){
		rep(j,k) dp[i+1][0]+=dp[i][j];
		rep(j,k-1) dp[i+1][j+1]=dp[i][j];
	}
	int ans=0;
	for(int j=1;j<k;j++) ans+=dp[n][j];
	cout<<ans<<endl;
	*/

	int dp[1000002],sum=1;
	dp[0]=1;
	dp[1]=0;
	rep(i,n){
		dp[i+2]=sum;
		sum=(sum+dp[i+2])%MOD;
		if(i>=k-2) sum=(sum-dp[i-k+2]+MOD)%MOD;
	}
	int ans=0;
	rep(i,k-1) ans=(ans+dp[n-i])%MOD;
	cout<<ans<<endl;

	return 0;
}
