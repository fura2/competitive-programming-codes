#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

template<class T>
class lowest_common_ancestor{
	vector<int> dep;
	vector<vector<int>> par;
	vector<vector<T>> dist;
	const weighted_graph<T>& Tr;

	void dfs(int u,int p){
		for(const auto& e:Tr[u]) if(e.to!=p) {
			dep[e.to]=dep[u]+1;
			par[0][e.to]=u;
			dist[0][e.to]=e.wt;
			dfs(e.to,u);
		}
	}

public:
	lowest_common_ancestor(const weighted_graph<T>& Tr,int root):Tr(Tr){
		int n=Tr.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));
		dist.assign(h,vector<T>(n));

		dfs(root,-1);
		rep(i,h-1) rep(u,n) if(par[i][u]!=-1) {
			par[i+1][u]=par[i][par[i][u]];
			dist[i+1][u]=dist[i][u]+dist[i][par[i][u]];
		}
	}

	int lca(int u,int v)const{
		int h=par.size();

		if(dep[u]>dep[v]) swap(u,v);
		rep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];
		if(u==v) return u;

		for(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];
		return par[0][u];
	}

	T distance(int u,int v)const{
		int h=par.size();
		T res=0;
		int w=lca(u,v);
		rep(i,h){
			if((dep[u]-dep[w])>>i&1) res+=dist[i][u], u=par[i][u];
			if((dep[v]-dep[w])>>i&1) res+=dist[i][v], v=par[i][v];
		}
		return res;
	}
};

int main(){
	int n; scanf("%d",&n);
	weighted_graph<int> T(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge(T,u,v,c);
	}

	lowest_common_ancestor<int> LCA(T,0);

	int q; scanf("%d",&q);
	rep(_,q){
		int s,t; scanf("%d%d",&s,&t); s--; t--;
		printf("%d\n",LCA.distance(s,t));
	}

	return 0;
}
