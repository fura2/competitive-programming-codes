#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector next(40,vector(n,0));
	vector sum(40,vector(n,0LL));
	rep(i,n){
		next[0][i]=(i+a[i])%n;
		sum[0][i]=a[i];
	}
	rep(t,39) rep(i,n) {
		next[t+1][i]=next[t][next[t][i]];
		sum[t+1][i]=sum[t][i]+sum[t][next[t][i]];
	}

	int q; scanf("%d",&q);
	rep(_,q){
		lint k; scanf("%lld",&k);
		lint ans=0,x=0;
		rep(t,40) if(k>>t&1) {
			ans+=sum[t][x];
			x=next[t][x];
		}
		printf("%lld\n",ans);
	}

	return 0;
}
