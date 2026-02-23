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

int main(){
	int n,m,s,g; scanf("%d%d%d%d",&n,&m,&s,&g); s--; g--;
	vector<lint> a(n),b(n),c(n);
	rep(u,n) scanf("%lld%lld%lld",&a[u],&b[u],&c[u]);

	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		G[u].emplace_back(v,c);
		G[v].emplace_back(u,c);
	}

	vector<lint> d(n,INF);
	d[s]=0;
	priority_queue<pair<lint,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		lint d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d[u]<d0) continue;

		for(auto e:G[u]){
			int v=e.to;
			lint d2=max(d[u],c[u]);
			if((d2-c[u])%(a[u]+b[u])>=a[u]) d2+=(a[u]+b[u])-(d2-c[u])%(a[u]+b[u]);
			d2+=e.wt;
			if(d2<d[v]){
				d[v]=d2;
				Q.emplace(-d[v],v);
			}
		}
	}
	printf("%lld\n",d[g]);

	return 0;
}
