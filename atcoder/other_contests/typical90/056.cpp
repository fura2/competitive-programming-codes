#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,W; scanf("%d%d",&n,&W);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	vector dp(n+1,vector(W+1,-1));
	dp[0][0]=0;
	rep(i,n) rep(x,W+1) if(dp[i][x]!=-1) {
		if(x+a[i]<=W) dp[i+1][x+a[i]]=0;
		if(x+b[i]<=W) dp[i+1][x+b[i]]=1;
	}

	if(dp[n][W]==-1){
		puts("Impossible");
		return 0;
	}

	string ans;
	for(int i=n-1,x=W;i>=0;i--){
		if(dp[i+1][x]==0){
			ans+='A';
			x-=a[i];
		}
		else{
			ans+='B';
			x-=b[i];
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';

	return 0;
}
