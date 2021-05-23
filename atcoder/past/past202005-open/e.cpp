#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}
	vector<int> c(n);
	rep(u,n) scanf("%d",&c[u]);

	rep(_,q){
		int type,x; scanf("%d%d",&type,&x); x--;
		printf("%d\n",c[x]);
		if(type==1){
			for(int v:G[x]) c[v]=c[x];
		}
		else{
			int y; scanf("%d",&y);
			c[x]=y;
		}
	}

	return 0;
}
