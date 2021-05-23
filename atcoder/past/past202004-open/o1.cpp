#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

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

template<class T>
class lowest_common_ancestor{
	vector<int> dep;
	vector<vector<int>> par;
	const weighted_graph<T>& Tr;

	vector<vector<T>> cost;

	void dfs(int u,int p,int d){
		dep[u]=d;
		par[0][u]=p;
		for(const auto& e:Tr[u]) if(e.to!=p) {
			cost[0][e.to]=e.wt;
			dfs(e.to,u,d+1);
		}
	}

public:
	lowest_common_ancestor(const weighted_graph<T>& Tr,int root):Tr(Tr){
		int n=Tr.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));
		cost.assign(h,vector<T>(n,0));

		dfs(root,-1,0);
		rep(i,h-1) rep(u,n) if(par[i][u]!=-1) {
			par[i+1][u]=par[i][par[i][u]];
			cost[i+1][u]=max(cost[i][u],cost[i][par[i][u]]);
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

	T find_max(int u,int v){
		int h=par.size();

		if(dep[u]>dep[v]) swap(u,v);

		T res=0;
		rep(i,h) if((dep[v]-dep[u])>>i&1) {
			res=max(res,cost[i][v]);
			v=par[i][v];
		}
		if(u==v) return res;

		for(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) {
			res=max({res,cost[i][u],cost[i][v]});
			u=par[i][u];
			v=par[i][v];
		}
		res=max({res,cost[0][u],cost[0][v]});
		return res;
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<lint> G(n);
	vector<tuple<lint,int,int,int>> E(m);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_edge(G,u,v,lint(c));
		E[i]={c,u,v,i};
	}

	lint cost=0;
	weighted_graph<lint> MST(n);
	vector<bool> used(m);
	{
		auto E_tmp=E;
		sort(E.begin(),E.end());

		union_find U(n);
		for(const auto& e:E){
			if(U.size()==1) break;
			lint wt;
			int u,v,id; tie(wt,u,v,id)=e;
			if(!U.is_same(u,v)){
				U.unite(u,v);
				cost+=wt;
				MST[u].emplace_back(v,wt);
				MST[v].emplace_back(u,wt);
				used[id]=true;
			}
		}

		E=E_tmp;
	}

	lowest_common_ancestor<lint> LCA(MST,0);
	rep(i,m){
		if(used[i]){
			printf("%lld\n",cost);
		}
		else{
			lint c=get<0>(E[i]);
			int u=get<1>(E[i]),v=get<2>(E[i]);
			printf("%lld\n",cost-LCA.find_max(u,v)+c);
		}
	}

	return 0;
}
