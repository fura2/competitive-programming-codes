// Day 3: Finals

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
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<tuple<int,int,int>> E(m);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		E[i]={u,v,c};
	}

	sort(E.begin(),E.end(),[](auto e,auto f){
		return get<2>(e)<get<2>(f);
	});

	int ans=0;
	union_find U(n);
	for(auto [u,v,c]:E){
		if(U.size()==k) break;
		if(!U.is_same(u,v)){
			U.unite(u,v);
			ans+=c;
		}
	}
	printf("%d\n",ans);

	return 0;
}
