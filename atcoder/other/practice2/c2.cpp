#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using namespace atcoder;

using lint=long long;

void solve(){
	lint n,m,a,b; scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
	printf("%lld\n",floor_sum(n,m,a,b));
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
