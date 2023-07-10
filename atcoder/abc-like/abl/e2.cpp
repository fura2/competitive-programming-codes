#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using namespace atcoder;

using mint=modint998244353;

mint ten[2000001],one[2000001];

using S=pair<mint,int>;
using F=int;
S op(S x,S y){
	return make_pair(x.first*ten[y.second]+y.first,x.second+y.second);
}
S e(){ return make_pair(mint(0),0); }
S mapping(F f,S x){
	if(f==0){
		return x;
	}
	else{
		int len=x.second;
		return make_pair(f*one[len],len);
	}
}
F composition(F f,F g){ return f==0?g:f; }
F id(){ return 0; }

int main(){
	int n,q; scanf("%d%d",&n,&q);

	ten[0]=1;
	one[0]=0;
	rep(i,n){
		ten[i+1]=10*ten[i];
		one[i+1]=10*one[i]+1;
	}

	lazy_segtree<S,op,e,F,mapping,composition,id> ST(n);
	rep(i,n) ST.set(i,make_pair(mint(1),1));

	rep(i,q){
		int l,r,d; scanf("%d%d%d",&l,&r,&d); l--;
		ST.apply(l,r,d);
		printf("%d\n",ST.all_prod().first.val());
	}

	return 0;
}
