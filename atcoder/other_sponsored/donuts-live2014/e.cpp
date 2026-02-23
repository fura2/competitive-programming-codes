#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m),b(m),c(m);
	rep(i,m) scanf("%d%d%d",&a[i],&b[i],&c[i]), a[i]--, b[i]--;

	int dp[1<<16]={};
	rep(S,1<<n){
		rep(i,n) if((S>>i&1)==0) {
			int tmp=0;
			rep(j,m) if((S>>a[j]&1)==1 && b[j]==i) tmp+=c[j];
			dp[S|1<<i]=max(dp[S|1<<i],dp[S]+tmp);
		}
	}
	printf("%d\n",dp[(1<<n)-1]);

	return 0;
}
