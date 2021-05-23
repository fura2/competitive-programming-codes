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
	int n,m; scanf("%d%d",&n,&m);
	lint cost[3];
	rep(i,3) scanf("%lld",&cost[i]);
	string s; cin>>s;

	weighted_graph<lint> G(n+3);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
	}

	rep(u,n){
		if(s[u]=='A'){
			add_directed_edge(G,u,n,0LL); // u -(0)-> A
			add_directed_edge(G,n+1,u,cost[0]); // B -cost(AB)-> u
			add_directed_edge(G,n+2,u,cost[1]); // C -cost(AC)-> u
		}
		else if(s[u]=='B'){
			add_directed_edge(G,u,n+1,0LL); // u -(0)-> B
			add_directed_edge(G,n  ,u,cost[0]); // A -cost(AB)-> u
			add_directed_edge(G,n+2,u,cost[2]); // C -cost(BC)-> u
		}
		else{ // s[u]=='C'
			add_directed_edge(G,u,n+2,0LL); // u -(0)-> C
			add_directed_edge(G,n  ,u,cost[1]); // A -cost(AC)-> u
			add_directed_edge(G,n+1,u,cost[2]); // B -cost(BC)-> u
		}
	}

	printf("%lld\n",Dijkstra(G,0)[n-1]);

	return 0;
}
