#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using namespace atcoder;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	scc_graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		G.add_edge(u,v);
	}

	auto SCC=G.scc();

	printf("%ld\n",SCC.size());
	for(auto C:SCC){
		printf("%ld",C.size());
		for(int u:C) printf(" %d",u);
		puts("");
	}

	return 0;
}
