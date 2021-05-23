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

graph G;

set<int> S;
vector<pair<int,int>> E;

void dfs(int u,int p){
	S.erase(u);
	if(p!=-1) E.emplace_back(p,u);

	for(auto it=S.begin();it!=S.end();){
		int v=*it;
		if(binary_search(G[u].begin(),G[u].end(),v)){
			++it;
		}
		else{
			dfs(v,u);
			it=S.upper_bound(v);
		}
	}
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	G.resize(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}
	rep(u,n) sort(G[u].begin(),G[u].end());

	rep(u,n) S.emplace(u);
	dfs(0,-1);

	if(E.size()<n-1){
		puts("No");
	}
	else{
		puts("Yes");
		for(auto [u,v]:E) printf("%d %d\n",u+1,v+1);
	}

	return 0;
}
