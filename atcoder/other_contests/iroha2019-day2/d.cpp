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

pair<lint,int> operator+=(pair<lint,int>& a,const pair<lint,int>& b){
	a.first+=b.first;
	return a;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<pair<lint,int>> G(n);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,make_pair(-c,i));
	}

	auto T=Kruskal(G).second;

	vector<int> ans;
	rep(u,n) for(auto e:T[u]) ans.emplace_back(e.wt.second);
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	for(int u:ans) printf("%d\n",u+1);

	return 0;
}
