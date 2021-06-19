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
	int n,m;
	lint L; scanf("%d%d%lld",&n,&m,&L);
	weighted_graph<pair<lint,int>> G(n);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		add_directed_edge(G,u,v,make_pair(c,0));
		add_directed_edge(G,v,u,make_pair(c,1));
	}

	vector d(n,vector<lint>(n,INF));
	d[0][0]=0;
	priority_queue<tuple<lint,int,int>> Q;
	Q.emplace(0,0,0);
	while(!Q.empty()){
		lint d0;
		int u,i; tie(d0,u,i)=Q.top(); Q.pop();
		d0*=-1;
		if(d0>d[u][i]) continue;

		for(auto [v,wt]:G[u]){
			auto [cost,dir]=wt;
			int i2=(dir==0?i:i+1);
			if(i2<n && d[v][i2]>d[u][i]+cost){
				d[v][i2]=d[u][i]+cost;
				Q.emplace(-d[v][i2],v,i2);
			}
		}
	}

	rep(i,n) if(d[n-1][i]<=L) {
		printf("%d\n",i);
		return 0;
	}
	puts("-1");

	return 0;
}
