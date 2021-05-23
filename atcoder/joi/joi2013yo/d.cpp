#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int d,n; scanf("%d%d",&d,&n);
	vector<int> t(d),a(n),b(n),c(n);
	rep(i,d) scanf("%d",&t[i]);
	rep(j,n) scanf("%d%d%d",&a[j],&b[j],&c[j]);

	vector dp(d,vector(n,-INF));
	rep(j,n) if(a[j]<=t[0] && t[0]<=b[j]) dp[0][j]=0;
	for(int i=1;i<d;i++){
		rep(j,n) if(dp[i-1][j]!=-INF) {
			rep(k,n) if(a[k]<=t[i] && t[i]<=b[k]) {
				dp[i][k]=max(dp[i][k],dp[i-1][j]+abs(c[j]-c[k]));
			}
		}
	}
	printf("%d\n",*max_element(dp[d-1].begin(),dp[d-1].end()));

	return 0;
}
