#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph T;
lint sz[200000],ans[200000];

void dfs(int u,int p){
	sz[u]=1;

	vector<lint> seq;
	for(int v:T[u]) if(v!=p) {
		dfs(v,u);
		sz[u]+=sz[v];
		seq.emplace_back(sz[v]);
	}

	ans[u]=(sz[u]-1)*(sz[u]-1);
	for(auto k:seq) ans[u]-=k*k;
	ans[u]+=2*sz[u]-1;
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	dfs(0,-1);

	rep(u,n) printf("%lld\n",ans[u]);

	return 0;
}
