#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n),c(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);
	rep(i,n) scanf("%lld",&c[i]);

	lint lo=-INF,hi=INF;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		lint cons=a[0]+b[0];
		vector<bool> dp(n);
		if(a[0]+b[0]+c[0]>=mi){
			dp[0]=true;
		}
		for(int i=1;i<n;i++){
			if(cons+a[i]+c[i]>=mi || (dp[i-1] && a[i]+b[i]+c[i]>=mi)){
				dp[i]=true;
			}
			cons+=a[i];
			if(dp[i-1]){
				cons=max(cons,a[i]+b[i]);
			}
		}

		if(dp[n-1]) lo=mi;
		else        hi=mi;
	}
	printf("%lld\n",lo);

	return 0;
}
