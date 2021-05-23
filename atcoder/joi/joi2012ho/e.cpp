#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		T d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, Q.emplace(-d[v],v);
		}
	}
	return d;
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

int main(){
	int n,m,k,q; scanf("%d%d%d%d",&n,&m,&k,&q);
	vector<tuple<int,int,int>> E(m);
	weighted_graph<int> G(n+1);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		E[i]={u,v,c};
		add_undirected_edge(G,u,v,c);
	}
	int src=n;
	rep(i,k){
		int u; scanf("%d",&u); u--;
		add_directed_edge(G,src,u,0);
	}
	vector<int> s(q),t(q);
	rep(i,q) scanf("%d%d",&s[i],&t[i]), s[i]--, t[i]--;

	auto d=Dijkstra(G,src);
	sort(E.begin(),E.end(),[&](auto e,auto f){
		auto [u1,v1,c1]=e;
		auto [u2,v2,c2]=f;
		return min(d[u1],d[v1])>min(d[u2],d[v2]);
	});

	// parallel binary search
	vector<int> lo(q,-1),hi(q,m+1);
	rep(_,30){
		vector<int> mi(q);
		rep(i,q) mi[i]=(lo[i]+hi[i])/2;

		vector Ev(m+1,vector<int>());
		rep(i,q) Ev[mi[i]].emplace_back(i);

		union_find U(n);
		rep(i,m+1){
			for(auto id:Ev[i]){
				if(U.is_same(s[id],t[id])) hi[id]=mi[id];
				else                       lo[id]=mi[id];
			}
			if(i<m){
				auto [u,v,c]=E[i];
				U.unite(u,v);
			}
		}
	}

	rep(i,q){
		assert(hi[i]>0);
		auto [u,v,c]=E[hi[i]-1];
		printf("%d\n",min(d[u],d[v]));
	}

	return 0;
}
