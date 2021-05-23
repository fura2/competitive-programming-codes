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
	int n,m,s; scanf("%d%d%d",&n,&m,&s), s--;
	vector<int> num(n);
	rep(u,n) scanf("%d",&num[u]);
	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge<lint>(G,u,v,c);
	}

	if(count(num.begin(),num.end(),0)==n-1) return puts("0"),0;

	auto d0=Dijkstra(G,s);

	lint ans=INF;
	rep(c,n){
		auto d=Dijkstra(G,c);
		lint sum=0;
		rep(u,n) sum+=2*num[u]*d[u];
		rep(u,n) if(num[u]>0) {
			ans=min(ans,d0[u]+d[u]+sum-2*d[u]);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
