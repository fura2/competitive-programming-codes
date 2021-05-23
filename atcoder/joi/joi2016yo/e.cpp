#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

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

int main(){
	int n,m,k,l; scanf("%d%d%d%d",&n,&m,&k,&l);
	int p,q; scanf("%d%d",&p,&q);
	vector<int> c(k);
	rep(i,k) scanf("%d",&c[i]), c[i]--;

	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}

	vector<int> d(n,-1);
	queue<int> Q;
	rep(i,k){
		d[c[i]]=0;
		Q.emplace(c[i]);
	}
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		if(d[u]==l) continue;
		for(int v:G[u]) if(d[v]==-1) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}

	weighted_graph<lint> H(n);
	rep(u,n) if(d[u]!=0) for(int v:G[u]) if(d[v]!=0) {
		lint cost;
		if     (v==n-1)   cost=0;
		else if(d[v]==-1) cost=p;
		else              cost=q;
		add_directed_edge(H,u,v,cost);
	}
	printf("%lld\n",Dijkstra(H,0)[n-1]);

	return 0;
}
