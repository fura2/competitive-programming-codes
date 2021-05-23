#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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

weighted_graph<lint> G;
vector<bool> vis;

int dfs(int u,lint c){
	vis[u]=true;
	int res=0;
	for(auto e:G[u]) if(e.wt<=c) {
		res++;
		if(!vis[e.to]) res+=dfs(e.to,c);
	}
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> val(n);
	rep(u,n) scanf("%lld",&val[u]);
	G.resize(n);
	vector<tuple<lint,int,int>> E(m);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
		E[i]={c,u,v};
	}

	sort(E.begin(),E.end());

	vector<bool> good(m);
	{
		union_find U(n);
		vector<lint> vsum=val;
		rep(i,m){
			auto [c,u,v]=E[i];
			if(U.is_same(u,v)){
				if(c<=vsum[U.find(u)]) good[i]=true;
			}
			else{
				u=U.find(u);
				v=U.find(v);
				U.unite(u,v);
				int r=U.find(u);
				vsum[r]=vsum[u]+vsum[v];
				if(c<=vsum[r]) good[i]=true;
			}
		}
	}

	int res=0;
	vis.assign(n,false);
	for(int i=m-1;i>=0;i--) if(good[i]) {
		auto [c,u,v]=E[i];
		if(!vis[u]) res+=dfs(u,c);
	}
	printf("%d\n",m-res/2);

	return 0;
}
