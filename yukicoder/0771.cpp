#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	static int dp[1<<18][18];
	rep(S,1<<n) rep(i,n) dp[S][i]=INF;
	rep(i,n) dp[1<<i][i]=0;
	rep(S,1<<n) rep(i,n) if(dp[S][i]<INF) {
		rep(j,n) if((S>>j&1)==0) {
			dp[S|(1<<j)][j]=min(dp[S|(1<<j)][j],max(dp[S][i],b[i]-a[i]+a[j]));
		}
	}
	printf("%d\n",*min_element(dp[(1<<n)-1],dp[(1<<n)-1]+n));

	return 0;
}
