#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

template<class T>
class strongly_connected_components{ strongly_connected_components(const T&)=delete; };

template<>
class strongly_connected_components<graph>{
	vector<int> id;
	vector<vector<int>> Comp;
	graph D;

public:
	strongly_connected_components(const graph& G={}){ build(G); }

	void build(const graph& G){
		int n=G.size();
		graph G_rev(n);
		rep(u,n) for(int v:G[u]) add_directed_edge(G_rev,v,u);

		int k;
		vector<int> top(n);

		auto dfs1=[&](auto&& dfs1,int u)->void{
			id[u]=0;
			for(int v:G[u]) if(id[v]==-1) dfs1(dfs1,v);
			top[k++]=u;
		};
		auto dfs2=[&](auto&& dfs2,int u)->void{
			id[u]=k;
			for(int v:G_rev[u]) if(id[v]==-1) dfs2(dfs2,v);
		};

		k=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs1(dfs1,u);

		reverse(top.begin(),top.end());

		k=0;
		id.assign(n,-1);
		for(int u:top) if(id[u]==-1) dfs2(dfs2,u), k++;

		Comp.resize(k);
		D.resize(k);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(int v:G[u]) if(id[u]!=id[v]) add_directed_edge(D,id[u],id[v]);
		}
	}

	int operator[](int u)const{ return id[u]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const graph& DAG()const{ return D; }
};

vector<bool> offline_reachability(const graph& G,vector<pair<int,int>> Q){
	strongly_connected_components SCC(G);
	for(auto& [u,v]:Q){
		u=SCC[u];
		v=SCC[v];
	}

	vector<bool> res(Q.size());
	vector<int> C;
	rep(i,Q.size()){
		int u,v; tie(u,v)=Q[i];
		if(u==v) res[i]=true;
		else     C.emplace_back(i);
	}

	const auto& D=SCC.DAG();
	int n=D.size();
	for(int l=0;l<C.size();l+=64){
		int r=min(l+64,int(C.size()));
		vector<int64_t> dp(n);
		for(int i=l;i<r;i++){
			dp[Q[C[i]].first]|=int64_t(1)<<(i-l);
		}
		rep(u,n) for(int v:D[u]) dp[v]|=dp[u];
		for(int i=l;i<r;i++){
			res[C[i]]=dp[Q[C[i]].second]>>(i-l)&1;
		}
	}

	return res;
}

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_directed_edge(G,u,v);
	}

	vector<pair<int,int>> Q(q);
	rep(i,q){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		Q[i]={u,v};
	}

	for(auto b:offline_reachability(G,Q)) puts(b?"Yes":"No");

	return 0;
}
