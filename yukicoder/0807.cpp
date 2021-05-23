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

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	const T INF=numeric_limits<T>::max();
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

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<lint> G(2*n),H(2*n);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
		add_undirected_edge(G,u+n,v+n,c);
		add_directed_edge(G,u,v+n,0LL);
		add_undirected_edge(H,u,v,c);
		add_undirected_edge(H,u+n,v+n,c);
		add_directed_edge(H,v,u+n,0LL);
	}

	auto d1=Dijkstra(G,0);
	auto d2=Dijkstra(H,0);
	rep(u,n) printf("%lld\n",min({d1[u]+d2[u],d1[u]+d2[u+n],d1[u+n]+d2[u]}));

	return 0;
}
