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
	int n,m; scanf("%d%d",&n,&m);

	lint sum=0;
	weighted_graph<lint> G(n+1);
	rep(u,n){
		lint a; scanf("%lld",&a);
		sum+=a;
		add_directed_edge(G,u,u+1,a);
		add_directed_edge(G,u+1,u,0LL);
	}
	rep(i,m){
		int l,r;
		lint w; scanf("%d%d%lld",&l,&r,&w); l--;
		add_directed_edge(G,l,r,w);
	}

	printf("%lld\n",sum-Dijkstra(G,0)[n]);

	return 0;
}
