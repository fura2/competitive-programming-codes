#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

void solve(){
	int x,y;
	string s; cin>>x>>y>>s;
	int n=s.length();

	vector dp(n,vector(2,INF));
	if(s[0]!='J') dp[0][0]=0;
	if(s[0]!='C') dp[0][1]=0;
	for(int i=1;i<n;i++){
		if(s[i]!='J') dp[i][0]=min(dp[i-1][0],dp[i-1][1]+y);
		if(s[i]!='C') dp[i][1]=min(dp[i-1][1],dp[i-1][0]+x);
	}
	printf("%d\n",min(dp[n-1][0],dp[n-1][1]));
}

int main(){
	int t; scanf("%d",&t);
	rep(_,t){
		printf("Case #%d: ",_+1);
		solve();
	}
	return 0;
}
