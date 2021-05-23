#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(u,n) scanf("%d",&a[u]);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_edge(G,u,v);
		add_edge(G,v,u);
	}

	rep(u,n){
		for(int v:G[u]) if(a[v]!=a[u]) for(int w:G[u]) if(a[w]!=a[u] && a[w]!=a[v]) {
			if(min({a[u],a[v],a[w]})==a[u] || max({a[u],a[v],a[w]})==a[u]) return puts("YES"),0;
		}
	}
	puts("NO");

	return 0;
}
