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

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	vector<int> deg(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
		deg[u]++;
		deg[v]++;
	}

	int th=sqrt(2*m);
	graph L(n); // graph of large vertices
	rep(u,n) if(deg[u]>th) {
		for(int v:G[u]) if(deg[v]>th) {
			add_directed_edge(L,u,v);
		}
	}

	int q; scanf("%d",&q);
	vector<pair<int,int>> query(q);
	vector<int> t_last(n,-1),t_from_small(n,-1);
	rep(t,q){
		int u,c; scanf("%d%d",&u,&c); u--;
		query[t]={u,c};

		if(deg[u]<=th){ // small vertex
			int idx=t_last[u];
			for(int v:G[u]){
				idx=max(idx,t_last[v]);
			}
			printf("%d\n",idx==-1?1:query[idx].second);
			for(int v:G[u]) t_from_small[v]=t;
		}
		else{ // large vertex
			int idx=max(t_last[u],t_from_small[u]);
			for(int v:L[u]){
				idx=max(idx,t_last[v]);
			}
			printf("%d\n",idx==-1?1:query[idx].second);
		}
		t_last[u]=t;
	}

	return 0;
}
