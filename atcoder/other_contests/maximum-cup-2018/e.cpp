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

class lowest_common_ancestor{
	vector<int> dep;
	vector<vector<int>> par;

public:
	lowest_common_ancestor(const graph& T,int root){
		int n=T.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));

		auto dfs=[&](auto&& dfs,int u,int p)->void{
			for(int v:T[u]) if(v!=p) {
				dep[v]=dep[u]+1;
				par[0][v]=u;
				dfs(dfs,v,u);
			}
		};

		dfs(dfs,root,-1);
		rep(i,h-1) rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];
	}

	int lca(int u,int v)const{
		int h=par.size();

		if(dep[u]>dep[v]) swap(u,v);
		rep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];
		if(u==v) return u;

		for(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];
		return par[0][u];
	}

	int distance(int u,int v)const{ return dep[u]+dep[v]-2*dep[lca(u,v)]; }
};

int main(){
	int q; scanf("%d",&q);
	vector<tuple<char,int,int>> Q(q);
	rep(i,q){
		char type;
		int u,v; scanf(" %c%d%d",&type,&u,&v); u--; v--;
		Q[i]={type,u,v};
	}

	int n=0;
	rep(i,q) n=max(n,get<2>(Q[i])+1);
	graph T(n);
	rep(i,q){
		char type;
		int u,v; tie(type,u,v)=Q[i];
		if(type=='A') add_undirected_edge(T,u,v);
	}
	lowest_common_ancestor LCA(T,0);

	rep(i,q){
		char type;
		int u,v; tie(type,u,v)=Q[i];
		if(type=='B'){
			printf("%d\n",LCA.distance(u,v)-1);
		}
	}

	return 0;
}
