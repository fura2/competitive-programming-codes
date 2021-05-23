#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

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

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_undirected_edge(G,u,v,lint(c));
	}

	vector d(n,vector(28,INF));
	d[0][0]=0;
	priority_queue<tuple<lint,int,int>,vector<tuple<lint,int,int>>,greater<>> Q;
	Q.emplace(0,0,0);
	while(!Q.empty()){
		auto [d0,u,mod]=Q.top(); Q.pop();
		if(d0>d[u][mod] || u==n-1) continue;

		for(auto e:G[u]){
			int mod2=(mod+e.wt)%28;
			if(d[e.to][mod2]>d0+e.wt){
				d[e.to][mod2]=d0+e.wt;
				Q.emplace(d[e.to][mod2],e.to,mod2);
			}
		}
	}

	lint ans=INF;
	rep(mod,28) if(mod%4==0 || mod%7==0) ans=min(ans,d[n-1][mod]);
	printf("%lld\n",ans);

	return 0;
}
