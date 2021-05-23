#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int dp[1<<15];
	rep(S,1<<n) dp[S]=INF;
	dp[0]=0;
	rep(S,1<<n){
		int sum=0;
		rep(i,n) if(S>>i&1) sum+=a[i];
		rep(i,n) if((S>>i&1)==0) {
			dp[S|1<<i]=min(dp[S|1<<i],dp[S]+max(a[i]-sum%1000,0));
		}
	}
	printf("%d\n",dp[(1<<n)-1]);

	return 0;
}
