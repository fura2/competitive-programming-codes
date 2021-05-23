#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int n,m;
graph G;
lint val[50];

bool vis[50];

lint dfs(int u){
	vis[u]=true;
	lint res=val[u];
	for(int v:G[u]) if(!vis[v]) {
		res=max(res,val[u]+dfs(v));
	}
	vis[u]=false;
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	G.resize(n);
	rep(u,n) scanf("%lld",&val[u]);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}

	lint ans=0;
	rep(u,n) ans=max(ans,dfs(u));
	printf("%lld\n",ans);

	return 0;
}
