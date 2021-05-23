#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

class lowest_common_ancestor{
	vector<int> dep;
	vector<vector<int>> par;
	const graph& T;

	void dfs(int u,int p){
		for(int v:T[u]) if(v!=p) {
			dep[v]=dep[u]+1;
			par[0][v]=u;
			dfs(v,u);
		}
	}

public:
	lowest_common_ancestor(const graph& T,int root):T(T){
		int n=T.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));

		dfs(root,-1);
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
lowest_common_ancestor* LCA;

vector<int> sz;

void dfs0(int u,int p){
	sz[u]=1;
	for(int v:T[u]) if(v!=p) dfs0(v,u), sz[u]+=sz[v];
}

vector<int> to,from;

void dfs(int u,int p){
	vector<int> single;
	int v0;
	for(int v:T[u]) if(v!=p) {
		if(sz[v]==1){
			single.emplace_back(v);
		}
		else{
			dfs(v,u);
			v0=v;
		}
	}

	if(!single.empty()){
		single.emplace_back(u);
		int k=single.size();
		rep(i,k){
			to[single[i]]=single[(i+1)%k];
			from[single[(i+1)%k]]=single[i];
		}
	}
	else{
		if(LCA->distance(v0,from[v0])==1){
			int w=from[v0];
			to[w]=u; from[u]=w;
			to[u]=v0; from[v0]=u;
		}
		else if(LCA->distance(v0,to[v0])==1){
			int w=to[v0];
			to[u]=w; from[w]=u;
			to[v0]=u; from[u]=v0;
		}
		else{
			assert(0);
		}
	}
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	union_find U(n);
	T.resize(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		if(!U.is_same(u,v)){
			U.unite(u,v);
			T[u].emplace_back(v);
			T[v].emplace_back(u);
		}
	}

	LCA=new lowest_common_ancestor(T,0);

	sz.resize(n);
	dfs0(0,-1);

	to.resize(n);
	from.resize(n);
	dfs(0,-1);

	rep(u,n) printf("%d%c",to[u]+1,u<n-1?' ':'\n');

	return 0;
}
