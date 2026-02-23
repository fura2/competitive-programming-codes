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

struct edge{
	int u,v;
	lint wt;
	edge(){}
	edge(int u,int v,lint wt):u(u),v(v),wt(wt){}
};

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	vector<edge> E(m);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		E[i]={u,v,c};
	}

	sort(E.begin(),E.end(),[](const edge& e,const edge& f){
		return e.wt<f.wt;
	});

	multiset<int> S;
	rep(u,n) S.emplace(1);

	vector<pair<int,lint>> p={{1,0}};
	union_find U(n);
	for(auto e:E) if(!U.is_same(e.u,e.v)) {
		int k1=U.size(e.u);
		int k2=U.size(e.v);
		U.unite(e.u,e.v);

		int k3=U.size(e.u);
		S.erase(S.find(k1));
		S.erase(S.find(k2));
		S.emplace(k3);
		p.emplace_back(*S.begin(),e.wt);
	}

	rep(_,q){
		int k; scanf("%d",&k);
		auto it=lower_bound(p.begin(),p.end(),make_pair(k,-1LL));
		if(it==p.end()) puts("trumpet");
		else printf("%lld\n",it->second);
	}

	return 0;
}
