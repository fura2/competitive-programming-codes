#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	lint a,b; scanf("%lld%lld",&a,&b);

	int d;
	for(d=60;d>=0;d--) if((a>>d&1)!=(b>>d&1)) break;
	assert(d!=-1);

	vector<lint> ans;
	rep(i,d) if(a>>i&1) {
		a+=1LL<<i;
		ans.emplace_back(1LL<<i);
	}
	for(int i=d;i>=0;i--) if((a>>i&1)!=(b>>i&1)) {
		ans.emplace_back(1LL<<i);
	}

	printf("%ld\n",ans.size());
	rep(i,ans.size()) printf("%lld%c",ans[i],i+1<ans.size()?' ':'\n');
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
