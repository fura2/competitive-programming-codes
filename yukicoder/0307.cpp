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

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector<int> color(h*w);
	rep(i,h) rep(j,w) scanf("%d",&color[i*w+j]);

	vector<set<int>> G(h*w);
	rep(u,h*w){
		int y=u/w,x=u%w;
		if(y+1<h){
			G[u].emplace((y+1)*w+x);
			G[(y+1)*w+x].emplace(u);
		}
		if(x+1<w){
			G[u].emplace(y*w+(x+1));
			G[y*w+(x+1)].emplace(u);
		}
	}

	union_find U(h*w);
	auto connect=[&](int u,int v){
		u=U.find(u);
		v=U.find(v);
		if(U.is_same(u,v)) return;
		U.unite(u,v);

		if(U.find(u)==v) swap(u,v);
		for(int w:G[v]) if(w!=u) {
			G[w].erase(v);
			G[w].emplace(u);
		}
		G[u].merge(G[v]);
		G[u].erase(u);
		G[u].erase(v);
		G[v].clear();
	};

	rep(u,h*w){
		int y=u/w,x=u%w;
		if(y+1<h && color[u]==color[(y+1)*w+x]) connect(u,(y+1)*w+x);
		if(x+1<w && color[u]==color[y*w+(x+1)]) connect(u,y*w+(x+1));
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int y,x,c; scanf("%d%d%d",&y,&x,&c); y--; x--;

		int u=U.find(y*w+x);
		if(color[u]==c) continue;

		color[u]=c;
		set<int> To=G[u];
		for(int v:To) connect(u,v);
	}

	rep(i,h) rep(j,w) printf("%d%c",color[U.find(i*w+j)],j<w-1?' ':'\n');

	return 0;
}
