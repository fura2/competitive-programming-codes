#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
	vector<vector<int>> C;
public:
	union_find(int n):n(n),p(n,-1),C(n){
		rep(u,n) C[u].emplace_back(u);
	}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
			C[u].insert(C[u].end(),C[v].begin(),C[v].end());
			C[v].clear();
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
	vector<int> connected_component(int u){ return C[find(u)]; }
};

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	set<pair<int,int>> E;
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		E.emplace(u,v);
	}
	vector<pair<int,int>> F(q);
	rep(i,q){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		F[i]={u,v};
		E.erase({u,v});
	}

	union_find U(n);
	for(auto [u,v]:E) U.unite(u,v);

	vector<int> ans(n,-1);
	rep(u,n) if(U.is_same(0,u)) ans[u]=q;
	for(int i=q-1;i>=0;i--){
		auto [u,v]=F[i];
		if(U.is_same(0,u) && !U.is_same(0,v)){
			for(int w:U.connected_component(v)) ans[w]=i;
		}
		else if(U.is_same(0,v) && !U.is_same(0,u)){
			for(int w:U.connected_component(u)) ans[w]=i;
		}
		U.unite(u,v);
	}
	for(int u=1;u<n;u++) printf("%d\n",ans[u]==q?-1:ans[u]+1);

	return 0;
}
