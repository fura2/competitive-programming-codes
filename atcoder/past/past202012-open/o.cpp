#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> E(m);
	vector<int> deg(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		E[i]={u,v};
		deg[u]++;
		deg[v]++;
	}

	graph G(n);
	for(auto [u,v]:E){
		if(deg[u]<=deg[v]){
			add_directed_edge(G,u,v);
		}
		else{
			add_directed_edge(G,v,u);
		}
	}

	vector<int> cnt1(n),cnt2(n),pre(n);
	int q; scanf("%d",&q);
	rep(t,q){
		int type,u; scanf("%d%d",&type,&u); u--;
		if(type==1){
			cnt1[u]++;
			for(auto v:G[u]) cnt2[v]++;
		}
		else{
			int tmp=cnt2[u];
			for(auto v:G[u]) tmp+=cnt1[v];
			printf("%d\n",tmp-pre[u]);
			pre[u]=tmp;
		}
	}

	return 0;
}
