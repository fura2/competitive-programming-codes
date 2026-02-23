#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using namespace atcoder;

int main(){
	int n,q; scanf("%d%d",&n,&q);

	dsu U(n);
	rep(_,q){
		int t,u,v; scanf("%d%d%d",&t,&u,&v);
		if(t==0) U.merge(u,v);
		else     printf("%d\n",U.same(u,v));
	}

	return 0;
}
