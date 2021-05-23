#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
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

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	vector<string> color(n);
	rep(u,n) cin>>color[u];
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}

	union_find U(7*n);
	rep(u,n) for(int v:G[u]) {
		rep(c,7) if(color[u][c]=='1' && color[v][c]=='1') {
			U.unite(u*7+c,v*7+c);
		}
	}
	rep(u,n){
		rep(c,7){
			if(color[u][c]=='1' && color[u][(c+1)%7]=='1') {
				U.unite(7*u+c,7*u+(c+1)%7);
			}
			if(color[u][c]=='1' && color[u][(c+6)%7]=='1') {
				U.unite(7*u+c,7*u+(c+6)%7);
			}
		}
	}

	rep(_,q){
		int type,u,y; scanf("%d%d%d",&type,&u,&y); u--; y--;
		if(type==1){
			color[u][y]='1';
			for(int v:G[u]){
				rep(c,7) if(color[u][c]=='1' && color[v][c]=='1') {
					U.unite(u*7+c,v*7+c);
				}
			}
			rep(c,7){
				if(color[u][c]=='1' && color[u][(c+1)%7]=='1') {
					U.unite(7*u+c,7*u+(c+1)%7);
				}
				if(color[u][c]=='1' && color[u][(c+6)%7]=='1') {
					U.unite(7*u+c,7*u+(c+6)%7);
				}
			}
		}
		else{
			printf("%d\n",U.size(7*u));
		}
	}

	return 0;
}
