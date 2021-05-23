#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
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

graph T;

int dep[100000],par[100000];
int nxt[100000],color[100000];

void dfs(int u,int p){
	par[u]=nxt[u]=p;
	color[u]=-1;
	for(int v:T[u]) if(v!=p) {
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}

int go(int u,int w,int c){
	if(dep[u]<=dep[w]) return u;

	if(color[u]==-1){
		color[u]=c;
	}
	if(nxt[u]!=-1){
		nxt[u]=go(nxt[u],w,c);
	}
	return nxt[u];
}

int main(){
	int n,q; scanf("%d%d",&n,&q);
	T.resize(n);
	map<pair<int,int>,int> f;
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
		f[{u,v}]=i;
		f[{v,u}]=i;
	}

	vector<int> u(q),v(q),c(q);
	rep(i,q) scanf("%d%d%d",&u[i],&v[i],&c[i]), u[i]--, v[i]--, c[i]--;

	dfs(0,-1);

	lowest_common_ancestor LCA(T,0);

	for(int i=q-1;i>=0;i--){
		int w=LCA.lca(u[i],v[i]);
		go(u[i],w,c[i]);
		go(v[i],w,c[i]);
	}

	vector<int> ans(n-1);
	rep(u,n) for(int v:T[u]) {
		if(par[v]==u) ans[f[{u,v}]]=color[v];
		else          ans[f[{u,v}]]=color[u];
	}
	rep(i,n-1) printf("%d\n",ans[i]+1);

	return 0;
}
