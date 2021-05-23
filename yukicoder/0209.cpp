#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

void solve(){
	int n,a[100]; scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	int dp[2][100][100];
	rep(t,2){
		rep(i,n) rep(j,n) dp[t][i][j]=-INF;

		rep(i,n) dp[t][i][i]=1;
		for(int i=1;i<n;i++) rep(j,i) if(a[j]<a[i]) dp[t][j][i]=2;
		for(int i=2;i<n;i++){
			rep(j,i) if(a[j]<a[i]) rep(k,j) if(a[k]<a[j] && a[j]-a[k]<a[i]-a[j]) {
				dp[t][j][i]=max(dp[t][j][i],dp[t][k][j]+1);
			}
		}
		reverse(a,a+n);
	}

	int ans=0;
	rep(i,n){
		int tmp0=0,tmp1=0;
		rep(j,n){
			tmp0=max(tmp0,dp[0][j][i]);
			tmp1=max(tmp1,dp[1][j][n-i-1]);
		}
		ans=max(ans,tmp0+tmp1-1);
	}
	printf("%d\n",ans);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
