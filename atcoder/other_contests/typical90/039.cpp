#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int n;
graph T;
lint sz[100000];

lint dfs(int u,int p){
	lint res=0;
	sz[u]=1;
	for(int v:T[u]) if(v!=p) {
		res+=dfs(v,u);
		res+=sz[v]*(n-sz[v]);
		sz[u]+=sz[v];
	}
	return res;
}

int main(){
	scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	printf("%lld\n",dfs(0,-1));

	return 0;
}
