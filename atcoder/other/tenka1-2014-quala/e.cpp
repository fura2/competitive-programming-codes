#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

class strongly_connected_components{
	vector<int> id;
	vector<vector<int>> Comp;
	graph D;

public:
	strongly_connected_components(){}
	strongly_connected_components(const graph& G){
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

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	union_find U(h*w);
	rep(i,h) rep(j,w) {
		if(i<h-1 && B[i][j]==B[i+1][j]) U.unite(i*w+j,(i+1)*w+j);
		if(j<w-1 && B[i][j]==B[i][j+1]) U.unite(i*w+j,i*w+(j+1));
	}

	int n=0;
	vector<int> f(h*w,-1),g(h*w);
	rep(i,h) rep(j,w) if(f[U.find(i*w+j)]==-1) {
		f[U.find(i*w+j)]=n;
		g[n]=U.find(i*w+j);
		n++;
	}

	graph G(n);
	rep(i,h-1) rep(j,w) if(B[i][j]!=B[i+1][j]) {
		add_directed_edge(G,f[U.find(i*w+j)],f[U.find((i+1)*w+j)]);
	}

	strongly_connected_components SCC(G);
	auto D=SCC.DAG();
	rep(u,D.size()){
		sort(D[u].begin(),D[u].end());
		D[u].erase(unique(D[u].begin(),D[u].end()),D[u].end());
	}

	vector H(D.size(),vector(w,h));
	rep(i,h) rep(j,w) {
		int u=SCC[f[U.find(i*w+j)]];
		H[u][j]=min(H[u][j],i);
	}
	for(int u=int(D.size())-1;u>=0;u--){
		for(int v:D[u]){
			rep(j,w) H[u][j]=min(H[u][j],H[v][j]);
		}
	}

	vector<int> ans(D.size());
	rep(u,D.size()){
		rep(j,w) ans[u]+=h-H[u][j];
	}

	int q; cin>>q;
	rep(_,q){
		int x,y; cin>>y>>x; x--; y--;
		printf("%d\n",ans[SCC[f[U.find(x*w+y)]]]);
	}

	return 0;
}
