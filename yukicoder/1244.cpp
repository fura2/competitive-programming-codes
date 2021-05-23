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

const int INF=1<<29;

int main(){
	int n,m,a,b; scanf("%d%d%d%d",&n,&m,&a,&b), a--;
	graph G(n+2);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--;
		add_undirected_edge(G,u,v);
	}
	int s=n+1;
	rep(u,a+1) add_directed_edge(G,s,u);

	auto d=distance(G,s);

	int res=INF;
	for(int u=b;u<=n;u++) res=min(res,d[u]);
	printf("%d\n",res<INF?res-1:-1);

	return 0;
}
