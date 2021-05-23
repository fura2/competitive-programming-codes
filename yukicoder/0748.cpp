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

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

template<class T>
pair<T,weighted_graph<T>> Kruskal(const weighted_graph<T>& G){
	int n=G.size();
	vector<tuple<T,int,int>> E;
	rep(u,n) for(const auto& e:G[u]) {
		int v=e.to;
		if(u<v) E.emplace_back(e.wt,u,v);
	}

	sort(E.begin(),E.end());

	T ans{};
	weighted_graph<T> Res(n);
	union_find U(n);
	for(const auto& e:E){
		if(U.size()==1) break;
		T wt;
		int u,v; tie(wt,u,v)=e;
		if(!U.is_same(u,v)){
			U.unite(u,v);
			ans+=wt;
			Res[u].emplace_back(v,wt);
			Res[v].emplace_back(u,wt);
		}
	}
	return {ans,Res};
}

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<tuple<int,int,int>> E(m);
	rep(i,m){
		scanf("%d%d%d",&get<0>(E[i]),&get<1>(E[i]),&get<2>(E[i]));
		get<0>(E[i])--;
		get<1>(E[i])--;
	}
	vector<int> e(k);
	rep(i,k) scanf("%d",&e[i]), e[i]--;

	lint total=0;
	int idx=0;
	weighted_graph<lint> G(n);
	rep(i,m){
		if(idx<k && i==e[idx]){
			add_undirected_edge<lint>(G,get<0>(E[i]),get<1>(E[i]),0);
			idx++;
		}
		else{
			add_undirected_edge<lint>(G,get<0>(E[i]),get<1>(E[i]),get<2>(E[i]));
			total+=get<2>(E[i]);
		}
	}
	printf("%lld\n",total-Kruskal(G).first);

	return 0;
}
