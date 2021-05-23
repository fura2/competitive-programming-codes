#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,p[100]; cin>>n;
	rep(i,n) cin>>p[i];

	bool dp[10001]={true};
	rep(i,n) for(int w=10000;w>=p[i];w--) dp[w]|=dp[w-p[i]];
	cout<<count(dp,dp+10001,true)<<endl;

	return 0;
}
