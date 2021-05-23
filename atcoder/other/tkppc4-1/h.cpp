#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

template<class T> struct edge{
	int to;
	T wt1,wt2;
	edge(int to,const T& wt1,const T& wt2):to(to),wt1(wt1),wt2(wt2){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

int main(){
	int n,m;
	lint k; scanf("%d%d%lld",&n,&m,&k);

	vector<lint> t(n);
	for(int u=1;u<n-1;u++) scanf("%lld",&t[u]);

	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v;
		lint c,d; scanf("%d%d%lld%lld",&u,&v,&c,&d); u--; v--;
		G[u].emplace_back(v,c,d);
		G[v].emplace_back(u,c,d);
	}

	vector<lint> d(n,INF);
	d[0]=0;

	priority_queue<pair<lint,int>> Q;
	Q.emplace(0,0);
	while(!Q.empty()){
		lint d0=-Q.top().first;
		int u=Q.top().second; Q.pop();

		if(d0>d[u]) continue;

		for(auto e:G[u]){
			int v=e.to;
			lint next=(d[u]+t[u]+e.wt2-1)/e.wt2*e.wt2+e.wt1;
			if(d[v]>next){
				d[v]=next;
				Q.emplace(-next,v);
			}
		}
	}
	printf("%lld\n",d[n-1]<=k?d[n-1]:-1);

	return 0;
}
