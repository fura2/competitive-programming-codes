#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> x(n),y(n);
	rep(i,n) scanf("%lld%lld",&x[i],&y[i]);

	lint mx[1<<15]={};
	rep(S,1<<n){
		rep(i,n) if(S>>i&1) {
			for(int j=i+1;j<n;j++) if(S>>j&1) {
				mx[S]=max(mx[S],(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}
		}
	}

	vector<lint> C={0};
	rep(i,n) for(int j=i+1;j<n;j++) {
		C.emplace_back((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	}
	sort(C.begin(),C.end());
	C.erase(unique(C.begin(),C.end()),C.end());

	int lo=-1,hi=C.size()-1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		int dp[1<<15]; // dp[S] = (S をグループ分けするのに最小で何グループ必要か)
		rep(S,1<<n) dp[S]=(S==0?0:k+1);
		rep(S,1<<n){
			for(int T=S;T>=0;T--){
				T&=S;
				if(mx[S&~T]<=C[mi]){
					dp[S]=min(dp[S],dp[T]+1);
				}
			}
		}
		if(dp[(1<<n)-1]<=k) hi=mi;
		else                lo=mi;
	}
	printf("%lld\n",C[hi]);

	return 0;
}
