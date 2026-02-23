#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
using lint=long long;

using namespace std;
template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

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

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int s1,t1,s2,t2; scanf("%d%d%d%d",&s1,&t1,&s2,&t2); s1--; t1--; s2--; t2--;
	weighted_graph<lint> G1(n),G2(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&c,&u,&v); u--; v--;
		G1[u].emplace_back(v,c);
		G2[v].emplace_back(u,c);
	}

	auto d1=Dijkstra(G1,s1);
	auto d2=Dijkstra(G1,s2);
	auto d3=Dijkstra(G2,t1);
	auto d4=Dijkstra(G2,t2);

	if(d1[t1]>INF || d2[t2]>INF) return puts("Impossible"),0;

	vector<lint> wt1(n,INF),wt2(n,INF);
	rep(u,n){
		if(d1[u]<INF && d2[u]<INF) wt1[u]=d1[u]+d2[u];
		if(d3[u]<INF && d4[u]<INF) wt2[u]=d3[u]+d4[u];
	}

	int s=n,t=n+1;
	weighted_graph<lint> H(n+2);
	rep(u,n){
		H[u]=G1[u];
		H[s].emplace_back(u,wt1[u]);
		H[u].emplace_back(t,wt2[u]);
	}
	printf("%lld\n",min(d1[t1]+d2[t2],Dijkstra(H,s)[t]));

	return 0;
}
