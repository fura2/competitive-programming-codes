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
	priority_queue<pair<T,int>,vector<pair<T,int>>,greater<>> Q;
	Q.emplace(0,s);
	while(!Q.empty()){
		T d0;
		int u; tie(d0,u)=Q.top();
		Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(d[v],v);
			}
		}
	}
	return d;
}

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	int s,g; scanf("%d%d",&s,&g);
	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c);
		add_undirected_edge(G,u,v,c);
	}
	vector<lint> x(k+1),cost(k+1);
	rep(i,k){
		scanf("%lld%lld",&x[i+1],&cost[i+1]);
	}

	auto d1=Dijkstra(G,s);
	auto d2=Dijkstra(G,g);

	lint ans=LLONG_MAX;
	rep(u,n) if(d1[u]<LLONG_MAX && d2[u]<LLONG_MAX) {
		int i1=upper_bound(x.begin(),x.end(),d1[u])-x.begin()-1;
		int i2=upper_bound(x.begin(),x.end(),d2[u])-x.begin()-1;
		ans=min(ans,cost[i1]+cost[i2]);
	}
	printf("%lld\n",ans);

	return 0;
}
