#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

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

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<int> h(n),c(k);
	rep(i,n) scanf("%d",&h[i]);
	rep(i,k) scanf("%d",&c[i]), c[i]--;

	graph G(n+1);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		if(h[u]>h[v]) add_directed_edge(G,v,u);
		else          add_directed_edge(G,u,v);
	}
	rep(i,k) add_directed_edge(G,n,c[i]);

	auto d=distance(G,n);
	rep(u,n) printf("%d\n",d[u]<INT_MAX?d[u]-1:-1);

	return 0;
}
