#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

const int INF=1<<29;

graph T;
int dep[100000];

void dfs(int u,int p){
	for(int v:T[u]) if(v!=p) {
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	dfs(0,-1);

	int d[100000];
	queue<int> Q;
	rep(u,n){
		if(u!=0 && T[u].size()==1){
			d[u]=0;
			Q.emplace(u);
		}
		else{
			d[u]=INF;
		}
	}
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:T[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}

	rep(u,n) printf("%d\n",min(dep[u],d[u]));

	return 0;
}
