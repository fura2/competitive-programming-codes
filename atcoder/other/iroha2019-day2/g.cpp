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
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(-d[v],v);
			}
		}
	}
	return d;
}

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	weighted_graph<lint> G(n*(k+1));
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		rep(j,k+1) add_undirected_edge(G,u*(k+1)+j,v*(k+1)+j,c);
	}
	rep(u,n){
		int x;
		lint y; scanf("%d%lld",&x,&y);
		rep(j,k) add_directed_edge(G,u*(k+1)+j,u*(k+1)+min(j+x,k),y);
	}

	lint ans=Dijkstra(G,0)[(n-1)*(k+1)+k];
	printf("%lld\n",ans<LLONG_MAX?ans:-1);

	return 0;
}
