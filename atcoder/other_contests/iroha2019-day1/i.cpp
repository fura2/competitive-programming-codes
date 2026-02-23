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
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

const int INF=1<<29;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	weighted_graph<int> G(n);
	map<pair<int,int>,int> f; // ID
	f[{0,-1}]=0;
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
		if(f.count({u,c})==0) f[{u,c}]=f.size();
		if(f.count({v,c})==0) f[{v,c}]=f.size();
	}

	int N=f.size();
	vector<pair<int,int>> g(N);
	for(auto p:f) g[p.second]=p.first;

	int s=f[{0,-1}];
	vector<int> d(N,INF);
	d[s]=0;
	priority_queue<pair<int,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		int d0=-Q.top().first;
		int id=Q.top().second; Q.pop();
		if(d0>d[id]) continue;

		auto [u,c]=g[id];
		for(const auto& e:G[u]){
			int v=e.to;
			int id2=f[{v,e.wt}];
			int d2=d[id]+(e.wt==c?0:1);
			if(d[id2]>d2) d[id2]=d2, Q.emplace(-d[id2],id2);
		}
	}

	int ans=INF;
	rep(id,N) if(g[id].first==n-1) ans=min(ans,d[id]);
	printf("%d\n",ans<INF?k*ans:-1);

	return 0;
}
