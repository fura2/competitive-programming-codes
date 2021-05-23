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
	int n,m,p,q,T; scanf("%d%d%d%d%d",&n,&m,&p,&q,&T); p--; q--;
	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
	}

	auto d1=Dijkstra(G,0);
	auto d2=Dijkstra(G,p);
	auto d3=Dijkstra(G,q);

	if(d1[p]+d2[q]+d3[0]<=T){
		printf("%d\n",T);
		return 0;
	}

	lint ans=-1;
	rep(u,n) rep(v,n) {
		if(d1[u]+d1[v]+max(d2[u]+d2[v],d3[u]+d3[v])<=T){
			ans=max(ans,T-max(d2[u]+d2[v],d3[u]+d3[v]));
		}
	}
	printf("%lld\n",ans);

	return 0;
}
