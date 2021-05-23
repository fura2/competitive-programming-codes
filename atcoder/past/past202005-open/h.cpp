#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,L; scanf("%d%d",&n,&L);
	vector<bool> a(L);
	rep(i,n){
		int x; scanf("%d",&x);
		a[x]=true;
	}
	int T1,T2,T3; scanf("%d%d%d",&T1,&T2,&T3);

	vector<int> dp(L+4,INF);
	dp[0]=0;
	rep(x,L){
		dp[x+1]=min(dp[x+1],dp[x]+T1+(a[x]?T3:0));
		dp[x+2]=min(dp[x+2],dp[x]+T1+T2+(a[x]?T3:0));
		dp[x+4]=min(dp[x+4],dp[x]+T1+3*T2+(a[x]?T3:0));
	}

	int ans=dp[L];
	if(L-1>=0) ans=min(ans,dp[L-1]+(a[L-1]?T3:0)+T1/2+T2/2);
	if(L-2>=0) ans=min(ans,dp[L-2]+(a[L-2]?T3:0)+T1/2+3*T2/2);
	if(L-3>=0) ans=min(ans,dp[L-3]+(a[L-3]?T3:0)+T1/2+5*T2/2);
	printf("%d\n",ans);

	return 0;
}
