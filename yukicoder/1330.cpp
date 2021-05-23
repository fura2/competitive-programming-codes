#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,m,p; scanf("%lld%lld%lld",&n,&m,&p);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> b(n),e(n); // a[i] = b[i] * p^e[i]
	rep(i,n){
		for(b[i]=a[i];b[i]%p==0;b[i]/=p) e[i]++;
	}

	vector<lint> dp(1000,-1);
	dp[0]=1;
	rep(i,n){
		rep(w,1000-(e[i]+1)) if(dp[w]!=-1) {
			dp[w+e[i]+1]=min(max(dp[w+e[i]+1],dp[w]*b[i]),m);
		}
	}

	lint mx=*max_element(a.begin(),a.end());
	lint tar=m/mx+1;
	rep(w,1000){
		if(dp[w]>=tar){
			printf("%d\n",w+1);
			return 0;
		}
	}
	puts("-1");

	return 0;
}
