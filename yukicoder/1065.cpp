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
void add_edge(weighted_graph<T>& G,int u,int v,const T& wt){
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
	int n,m; scanf("%d%d",&n,&m);
	int s,t; scanf("%d%d",&s,&t); s--; t--;
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	weighted_graph<double> G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_edge(G,u,v,hypot(x[u]-x[v],y[u]-y[v]));
	}

	printf("%.9f\n",Dijkstra(G,s)[t]);

	return 0;
}
