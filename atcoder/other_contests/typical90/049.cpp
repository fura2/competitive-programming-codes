#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n=0){ build(n); }
	void build(int n){
		this->n=n;
		p.assign(n,-1);
	}
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

template<class T>
pair<bool,T> Kruskal(int n,vector<tuple<int,int,T>> E){
	sort(E.begin(),E.end(),[](const auto& e,const auto& f){
		return get<2>(e)<get<2>(f);
	});

	T total{};
	union_find U(n);
	for(const auto& [u,v,wt]:E){
		if(!U.is_same(u,v)){
			U.unite(u,v);
			total+=wt;
		}
	}
	return {U.size()==1,total};
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<tuple<int,int,lint>> E(m);
	rep(i,m){
		lint c;
		int l,r; scanf("%lld%d%d",&c,&l,&r); l--;
		E[i]={l,r,c};
	}

	auto res=Kruskal(n+1,E);
	printf("%lld\n",res.first?res.second:-1);

	return 0;
}
