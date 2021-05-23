#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=100000;

int main(){
	int n,m,s; cin>>n>>m>>s;

	int dp[2][3001][2001],curr=0,next=1;
	dp[0][0][0]=1;
	rep(i,n*n){
		memset(dp[next],0,sizeof dp[next]);
		rep(j,s){
			int sum=0;
			rep(k,m+1){
				if(j+k>s) break;
				dp[next][j+k][k]+=sum;
				if(dp[next][j+k][k]>=MOD) dp[next][j+k][k]-=MOD;
				sum+=dp[curr][j][k];
				if(sum>=MOD) sum-=MOD;
			}
		}
		swap(curr,next);
	}

	int ans=0;
	rep(k,m+1) ans=(ans+dp[n*n%2][s][k])%100000;
	cout<<ans<<endl;

	return 0;
}
