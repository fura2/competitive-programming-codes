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
	int x,y,z; cin>>x>>y>>z;
	char c1,c2;
	int t1,t2; cin>>c1>>t1>>c2>>t2;

	weighted_graph<int> G(8);
	add_edge(G,0,1,1);
	add_edge(G,0,2,1);
	add_edge(G,1,2,1);
	add_edge(G,3,4,1);
	add_edge(G,3,5,1);
	add_edge(G,4,5,1);
	add_edge(G,0,3,x-1);
	add_edge(G,1,4,y-1);
	add_edge(G,2,5,z-1);

	auto f=[&](char c,int t,int u){
		if(c=='A'){
			add_edge(G,0,u,t-1);
			add_edge(G,3,u,x-t);
		}
		else if(c=='B'){
			add_edge(G,1,u,t-1);
			add_edge(G,4,u,y-t);
		}
		else{
			add_edge(G,2,u,t-1);
			add_edge(G,5,u,z-t);
		}
	};
	f(c1,t1,6);
	f(c2,t2,7);
	if(c1==c2) add_edge(G,6,7,abs(t1-t2));

	cout<<Dijkstra(G,6)[7]<<'\n';

	return 0;
}
