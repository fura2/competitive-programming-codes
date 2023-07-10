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

const long long INF=1LL<<61;

int main(){
	int n,m,s,t; scanf("%d%d%d%d",&n,&m,&s,&t); s--; t--;
	weighted_graph<lint> G1(n),G2(n);
	rep(i,m){
		int u,v;
		lint c1,c2; scanf("%d%d%lld%lld",&u,&v,&c1,&c2); u--; v--;
		add_undirected_edge(G1,u,v,c1);
		add_undirected_edge(G2,u,v,c2);
	}

	auto d1=Dijkstra(G1,s);
	auto d2=Dijkstra(G2,t);

	vector<lint> ans(n);
	lint mn=INF;
	for(int u=n-1;u>=0;u--){
		mn=min(mn,d1[u]+d2[u]);
		ans[u]=1000000000000000-mn;
	}
	rep(u,n) printf("%lld\n",ans[u]);

	return 0;
}
