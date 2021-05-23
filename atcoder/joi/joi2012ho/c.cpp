#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T0,T1; scanf("%d%d%d",&n,&T1,&T0);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	vector<int> dp(T1+1);
	rep(i,n){
		for(int t=T1;t>=b[i];t--){
			if(!(t-b[i]<T0 && T0<t)){
				dp[t]=max(dp[t],dp[t-b[i]]+a[i]);
			}
		}
		rep(t,T1) dp[t+1]=max(dp[t+1],dp[t]);
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
