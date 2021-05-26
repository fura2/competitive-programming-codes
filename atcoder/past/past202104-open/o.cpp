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

template<class T>
class lowest_common_ancestor{ lowest_common_ancestor(const T&,int)=delete; };

template<>
class lowest_common_ancestor<graph>{
	vector<int> dep;
	vector<vector<int>> par;

public:
	lowest_common_ancestor(){}
	lowest_common_ancestor(const graph& T,int root){ build(T,root); }

	void build(const graph& T,int root){
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

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n=0){ build(n); }
	void build(int n){
		this->n=n;
		p.assign(n,-1);
	}
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

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph T(n);
	vector<pair<int,int>> E;
	union_find U(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		if(U.is_same(u,v)){
			E.emplace_back(u,v);
		}
		else{
			add_undirected_edge(T,u,v);
			U.unite(u,v);
		}
	}

	vector<int> V;
	for(auto [u,v]:E){
		V.emplace_back(u);
		V.emplace_back(v);
	}
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
	int N=V.size();

	lowest_common_ancestor LCA(T,0);
	vector d(N,vector(N,0));
	rep(i,N) for(int j=i+1;j<N;j++) d[i][j]=d[j][i]=LCA.distance(V[i],V[j]);
	for(auto [u,v]:E){
		int i=lower_bound(V.begin(),V.end(),u)-V.begin();
		int j=lower_bound(V.begin(),V.end(),v)-V.begin();
		d[i][j]=d[j][i]=1;
	}
	rep(k,N) rep(i,N) rep(j,N) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	int q; scanf("%d",&q);
	rep(_,q){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		int ans=LCA.distance(u,v);
		rep(i,N) rep(j,N) if(i!=j) ans=min(ans,LCA.distance(u,V[i])+d[i][j]+LCA.distance(V[j],v));
		printf("%d\n",ans);
	}

	return 0;
}
