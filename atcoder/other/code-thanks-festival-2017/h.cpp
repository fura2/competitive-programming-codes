#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class persistent_union_find{
	int n,t;
	vector<int> p,t0;
	vector<vector<pair<int,int>>> Sz;
public:
	persistent_union_find(int n):n(n),t(0),p(n,-1),t0(n,1e9),Sz(n,{make_pair(-1,1)}){}
	int find(int u,int t){
		while(t>t0[u]) u=find(p[u],t);
		return u;
	}
	void unite(int u,int v){
		u=find(u,t); v=find(v,t);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u;
			t0[v]=t;
			Sz[u].emplace_back(t,-p[u]);
			n--;
		}
		t++;
	}
	bool is_same(int u,int v,int t){ return find(u,t)==find(v,t); }
	int size(){ return n; }
	int size(int u,int t){
		u=find(u,t);
		return (--lower_bound(Sz[u].begin(),Sz[u].end(),make_pair(t,0)))->second;
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	persistent_union_find U(n);
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b); a--; b--;
		U.unite(a,b);
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		if(!U.is_same(u,v,m)){
			puts("-1");
		}
		else{
			int lo=0,hi=m;
			while(hi-lo>1){
				int mi=(lo+hi)/2;
				if(U.is_same(u,v,mi)) hi=mi;
				else                  lo=mi;
			}
			printf("%d\n",hi);
		}
	}

	return 0;
}
