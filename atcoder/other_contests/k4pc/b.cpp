#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n;
	lint m; scanf("%d%lld",&n,&m);

	lint ans=0;
	set<lint> S{m,-INF,INF};
	rep(i,n){
		lint c; scanf("%lld",&c);
		auto it=S.lower_bound(c);
		ans+=min(abs(c-*it),abs(c-*prev(it)));
		S.emplace(c);
	}
	printf("%lld\n",ans);

	return 0;
}
