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
	int n,m; scanf("%d%d",&n,&m);

	vector<int> Lang[100000];
	rep(i,n){
		int k; scanf("%d",&k);
		rep(_,k){
			int l; scanf("%d",&l); l--;
			Lang[l].emplace_back(i);
		}
	}

	union_find U(n);
	rep(l,m) rep(i,(int)Lang[l].size()-1) U.unite(Lang[l][i],Lang[l][i+1]);
	puts(U.size()==1?"YES":"NO");

	return 0;
}
