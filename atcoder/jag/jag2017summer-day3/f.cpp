#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

vector<int> distance(const graph& G,int s){
	const int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(2*n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v+n);
		add_undirected_edge(G,u+n,v);
	}

	auto d=distance(G,0);

	rep(u,2*n) if(d[u]==INT_MAX) {
		puts("-1");
		return 0;
	}

	int ans_e=0,ans_o=0;
	rep(u,n){
		ans_e=max(ans_e,d[u]);
		ans_o=max(ans_o,d[u+n]);
	}
	printf("%d\n",min(ans_e,ans_o));

	return 0;
}
