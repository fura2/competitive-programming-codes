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

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

const int INF=1<<29;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	n++;
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
	}
	rep(i,k){
		int u; scanf("%d",&u); u--;
		add_directed_edge(G,n-1,u,0);
	}

	vector<int> d(n,INF);
	d[n-1]=0;

	int ans=0;
	priority_queue<pair<int,int>> Q;
	Q.emplace(0,n-1);
	while(!Q.empty()){
		int d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(-d[v],v);
			}
			if(d[v]<=d[u]){
				ans=max(ans,(d[u]+d[v]+e.wt+1)/2);
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
