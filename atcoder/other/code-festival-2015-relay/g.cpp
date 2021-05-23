#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,l; scanf("%d%d%d",&n,&m,&l);
	vector<int> a(n),b(n),c(m),d(m);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);
	rep(j,m) scanf("%d%d",&c[j],&d[j]);

	vector dp(l+1,0);
	rep(j,m) for(int x=l;x>=c[j];x--) dp[x]=max(dp[x],dp[x-c[j]]+d[j]);
	rep(x,l) dp[x+1]=max(dp[x+1],dp[x]);

	int ans=0;
	rep(i,n) if(a[i]<=l) ans=max(ans,b[i]+dp[l-a[i]]);
	printf("%d\n",ans);

	return 0;
}
