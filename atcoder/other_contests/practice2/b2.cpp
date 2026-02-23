#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using namespace atcoder;

using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	fenwick_tree<lint> F(n);
	rep(i,n) F.add(i,a[i]);
	rep(_,q){
		int t,l,r; scanf("%d%d%d",&t,&l,&r);
		if(t==0) F.add(l,r);
		else     printf("%lld\n",F.sum(l,r));
	}

	return 0;
}
