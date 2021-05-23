#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[16]; scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	int dp[1<<16]={100};
	rep(S,1<<n){
		int hp=100;
		rep(i,n) if((S>>i&1)==1 && a[i]<0) hp+=100;
		rep(i,n) if((S>>i&1)==0 && dp[S]>0 && dp[S]>-a[i]) {
			dp[S|1<<i]=max(dp[S|1<<i],min(dp[S]+a[i],hp));
		}
	}
	printf("%d\n",dp[(1<<n)-1]);

	return 0;
}
