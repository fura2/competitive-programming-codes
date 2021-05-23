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

const int INF=INT_MAX;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<tuple<int,int,int,int>> E(m);
	rep(i,m){
		int u,v,c,d; scanf("%d%d%d%d",&u,&v,&c,&d); u--; v--;
		E[i]=make_tuple(u,v,c,d);
	}
	E.emplace_back(-1,-1,-1,0);

	assert(m<=1000);

	int ans=INF;
	rep(i,m+1){
		weighted_graph<int> G(n);
		rep(j,m){
			int u,v,cost,flip;
			tie(u,v,cost,flip)=E[j];
			if(j==i) G[v].emplace_back(u,cost);
			else     G[u].emplace_back(v,cost);
		}

		auto d1=Dijkstra(G,0);
		auto d2=Dijkstra(G,n-1);
		if(d1[n-1]<INF && d2[0]<INF) ans=min(ans,d1[n-1]+d2[0]+get<3>(E[i]));
	}
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
