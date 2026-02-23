#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

const int INF=1<<29;

graph T;
int val[1000];

void dfs(int u){
	if(T[u].empty()) return;
	if(u==0){
		for(int v:T[u]) dfs(v);
		return;
	}

	val[u]=INF;
	for(int v:T[u]){
		dfs(v);
		val[u]=min(val[u],val[v]);
	}
	for(int v:T[u]){
		val[v]-=val[u];
	}
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	T.resize(n);
	for(int u=1;u<n;u++){
		int p; scanf("%d",&p);
		add_directed_edge(T,p,u);
	}
	rep(i,m){
		int u,c; scanf("%d%d",&u,&c);
		val[u]=c;
	}

	dfs(0);

	printf("%d\n",accumulate(val,val+n,0));

	return 0;
}
