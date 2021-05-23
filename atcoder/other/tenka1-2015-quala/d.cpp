#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

const int INF=1<<29;

class two_edge_connected_components{
	int idx;
	vector<int> ord,low,id;
	const graph& G;
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

		Tr.resize(idx);
		rep(u,n) for(int v:G[u]) if(id[u]!=id[v]) Tr[id[u]].emplace_back(id[v]);
	}

	int operator[](int i)const{ return id[i]; }

	const vector<pair<int,int>>& bridges()const{ return B; }
	const graph& bridge_block_tree()const{ return Tr; }
};

graph T;

// sz[u] := number of vertices in the subtree with root u
// leaf[u] := number of leaves in the subtree with root u
int par[100000],sz[100000],leaf[100000];

void dfs(int u,int p){
	par[u]=p;
	sz[u]=1;
	leaf[u]=(T[u].size()==1?1:0);
	for(int v:T[u]) if(v!=p) {
		dfs(v,u);
		sz[u]+=sz[v];
		leaf[u]+=leaf[v];
	}
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	two_edge_connected_components TECC(G);
	T=TECC.bridge_block_tree();

	int k=T.size();
	vector<int> sz_orig(k); // sz_orig[u] := ( T の頂点 u が G の頂点いくつを縮約してできたか )
	rep(u,n) sz_orig[TECC[u]]++;

	int n_leaf=0;
	set<pair<int,int>> bad_edges;
	rep(u,k){
		if(T[u].size()==1) n_leaf++;
		for(int v:T[u]) if(u<v && sz_orig[u]==1 && sz_orig[v]==1) bad_edges.emplace(u,v);
	}

	dfs(0,-1);

	int ans=INF;
	rep(u,k) if(par[u]!=-1) {
		int p=par[u];

		if(sz[u]==2){
			int v=(T[u][0]==p?T[u][1]:T[u][0]);
			if(bad_edges.count(minmax(u,v))>0) continue;
		}

		if(k-sz[u]==2){
			int v=(T[p][0]==u?T[p][1]:T[p][0]);
			if(bad_edges.count(minmax(p,v))>0) continue;
		}

		int leafL=leaf[u]+(T[u].size()==2?1:0);
		int leafR=n_leaf-leafL+(T[p].size()==2?1:0);

		int costL,costR;
		if(sz[u]==1) costL=0;
		else         costL=(leafL+1)/2;
		if(k-sz[u]==1) costR=0;
		else           costR=(leafR+1)/2;

		ans=min(ans,costL+costR);
	}

	if(ans<INF) printf("%d\n",ans);
	else puts("IMPOSSIBLE");

	return 0;
}
