#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
	int n,m1,m2; scanf("%d%d%d",&n,&m1,&m2);

	union_find U1(n),U2(n);
	rep(i,m1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		U1.unite(u,v);
	}
	rep(i,m2){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		U2.unite(u,v);
	}

	vector<vector<int>> L(n);
	rep(u,n) L[U1.find(u)].emplace_back(U2.find(u));

	vector<int> cnt(n);
	rep(u,n){
		sort(L[u].begin(),L[u].end());
		L[u].erase(unique(L[u].begin(),L[u].end()),L[u].end());
		for(int v:L[u]) cnt[u]+=U2.size(v);
	}

	lint ans=0;
	rep(u,n) ans+=cnt[U1.find(u)]-1;
	printf("%lld\n",ans);

	return 0;
}
