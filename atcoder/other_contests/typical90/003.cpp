#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

pair<int,vector<int>> tree_diameter(const graph& T){
	int n=T.size();
	vector<int> pre(n,-1);

	auto dfs=[&](auto&& dfs,int u,int p)->pair<int,int>{
		int g=u,d_max=0;
		for(int v:T[u]) if(v!=p) {
			auto [d,w]=dfs(dfs,v,u);
			if(d+1>d_max){
				d_max=d+1;
				g=w;
			}
			pre[v]=u;
		}
		return {d_max,g};
	};
	int u0=dfs(dfs,0,-1).second;
	auto [diam,u1]=dfs(dfs,u0,-1);

	vector<int> P={u1};
	for(int u=u1;u!=u0;u=pre[u]){
		P.emplace_back(pre[u]);
	}
	reverse(P.begin(),P.end());

	return {diam,P};
}

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}
	printf("%d\n",tree_diameter(T).first+1);
	return 0;
}
