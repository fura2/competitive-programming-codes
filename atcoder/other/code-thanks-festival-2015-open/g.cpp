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

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<tuple<int,lint,lint>> G(n+1);
	vector<tuple<int,int,lint,lint>> E(2*m+1);
	rep(i,m){
		int u,v;
		lint c,t; scanf("%d%d%lld%lld",&u,&v,&c,&t); u--; v--; c--;
		add_directed_edge(G,u,v,make_tuple(2*i  ,c,t));
		add_directed_edge(G,v,u,make_tuple(2*i+1,c,t));
		E[2*i  ]={u,v,c,t};
		E[2*i+1]={v,u,c,t};
	}

	int s=n;
	add_directed_edge(G,s,0,make_tuple(2*m,0LL,0LL));
	E[2*m]={s,0,0,0};

	// 有効辺の終端を状態として Dijkstra
	vector<lint> d(2*m+1,INF);
	d[2*m]=0;
	priority_queue<pair<lint,int>> Q;
	Q.emplace(0,2*m);
	while(!Q.empty()){
		lint d0=-Q.top().first;
		int i=Q.top().second;
		Q.pop();

		if(d0>d[i]) continue;

		int u=get<1>(E[i]);
		lint c0=get<2>(E[i]);

		if(u==n-1){
			printf("%lld\n",d0);
			break;
		}

		for(auto e:G[u]){
			int i2;
			lint c2,t; tie(i2,c2,t)=e.wt;

			lint cost=abs(c0-c2)+t;
			if(d[i2]>d[i]+cost){
				d[i2]=d[i]+cost;
				Q.emplace(-d[i2],i2);
			}
		}
	}

	return 0;
}
