// Day 3: Route

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
	int n,m; scanf("%d%d",&n,&m);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
	}

	int d[100][100];
	rep(u,n) rep(v,n) d[u][v]=INF;
	d[0][0]=0;
	priority_queue<pair<int,pair<int,int>>> Q; Q.push({0,{0,0}});
	while(!Q.empty()){
		int d0=-Q.top().first;
		int u,p; tie(u,p)=Q.top().second;
		Q.pop();

		if(d0>d[u][p]) continue;

		for(const auto& e:G[u]){
			int v=e.to;
			if((x[p]-x[u])*(x[v]-x[u])+(y[p]-y[u])*(y[v]-y[u])>0) continue;
			if(d[v][u]>d[u][p]+e.wt){
				d[v][u]=d[u][p]+e.wt;
				Q.push({-d[v][u],{v,u}});
			}
		}
	}

	int ans=INF;
	rep(u,n) ans=min(ans,d[1][u]);
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
