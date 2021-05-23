#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

class two_edge_connected_components{
	int idx;
	vector<int> ord,low,id;
	const graph& G;

	vector<vector<int>> Comp;
	vector<pair<int,int>> B;
	graph Tr;

	void dfs1(int u,int p){
		ord[u]=low[u]=idx++;
		bool f=true;
		for(int v:G[u]){
			if(v==p && f){ f=false; continue; }
			if(ord[v]==-1){
				dfs1(v,u);
				low[u]=min(low[u],low[v]);
			}
			else{
				low[u]=min(low[u],ord[v]);
			}
		}
	}

	void dfs2(int u,int p){
		if(p==-1 || ord[p]<low[u]){
			id[u]=idx++;
			if(p!=-1) B.emplace_back(minmax(p,u));
		}
		else{
			id[u]=id[p];
		}
		for(int v:G[u]) if(id[v]==-1) dfs2(v,u);
	}

public:
	two_edge_connected_components(const graph& G):G(G){
		int n=G.size();

		idx=0;
		ord.assign(n,-1);
		low.assign(n,-1);
		rep(u,n) if(ord[u]==-1) dfs1(u,-1);

		idx=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs2(u,-1);

		Comp.resize(idx);
		Tr.resize(idx);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(int v:G[u]) if(id[u]!=id[v]) Tr[id[u]].emplace_back(id[v]);
		}
	}

	int operator[](int i)const{ return id[i]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const vector<pair<int,int>>& bridges()const{ return B; }
	const graph& bridge_block_tree()const{ return Tr; }
};

int main(){
	int n; scanf("%d",&n);
	graph G(n);
	vector<pair<int,int>> E(n);
	rep(i,n){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
		E[i]={u,v};
	}

	two_edge_connected_components TE(G);

	vector<int> ans;
	rep(i,n) if(TE[E[i].first]==TE[E[i].second]) ans.emplace_back(i);
	printf("%ld\n",ans.size());
	rep(i,ans.size()) printf("%d%c",ans[i]+1,i+1<ans.size()?' ':'\n');

	return 0;
}
