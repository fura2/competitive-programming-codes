#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

graph G(101);
bool vis[101];

int dfs(int u){
	int res=0;
	for(int v:G[u]) if(!vis[v]) {
		vis[v]=true;
		res=max(res,dfs(v)+1);
		vis[v]=false;
	}
	return res;
}

int main(){
	int m; scanf("%d",&m);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}
	rep(u,100) add_directed_edge(G,100,u);

	vis[100]=true;
	printf("%d\n",dfs(100));

	return 0;
}
