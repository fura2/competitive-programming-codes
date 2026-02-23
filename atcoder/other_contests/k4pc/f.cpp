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
vector<T> Bellman_Ford(const weighted_graph<T>& G,int s){
	const T INF=numeric_limits<T>::max();

	int n=G.size();
	vector<T> d(n,INF);
	d[s]=0;
	rep(_,n-1){
		bool upd=false;
		rep(u,n) if(d[u]<INF) for(const auto& e:G[u]) {
			int v=e.to;
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, upd=true;
		}
		if(!upd) return d;
	}

	queue<int> Q;
	rep(u,n) if(d[u]<INF) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>-INF && (d[u]==-INF || d[v]>d[u]+e.wt)) d[v]=-INF, Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),k(n),d(n);
	rep(i,n) scanf("%d%d%d",&x[i],&k[i],&d[i]);

	map<int,int> hist;
	rep(i,n) ++hist[x[i]];

	vector<int> X={-INT_MAX,INT_MAX};
	rep(i,n) rep(j,2) {
		X.emplace_back(x[i]-j);
		X.emplace_back(x[i]-d[i]-j);
		X.emplace_back(x[i]+d[i]-j);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	int N=X.size();
	weighted_graph<lint> G(N);
	rep(u,N-1){
		G[u+1].emplace_back(u,0);
	}
	for(auto p:hist){
		int u=lower_bound(X.begin(),X.end(),p.first)-X.begin();
		G[u].emplace_back(u-1,-p.second);
	}
	rep(i,n){
		int u=lower_bound(X.begin(),X.end(),x[i]-d[i])-X.begin();
		int v=lower_bound(X.begin(),X.end(),x[i]+d[i])-X.begin();
		G[u].emplace_back(v-1,k[i]-1);
		G[v].emplace_back(u-1,-k[i]);
	}

	auto dist=Bellman_Ford(G,N-1);

	if(dist[0]==-LLONG_MAX) return puts("impossible"),0;
	if(-dist[0]-n>1e5)      return puts("too many"),0;

	vector<int> ans;
	rep(i,N-1) rep(_,dist[i+1]-dist[i]-hist[X[i+1]]) ans.emplace_back(X[i+1]);

	printf("%lu\n",ans.size());
	rep(i,ans.size()) printf("%d%c",ans[i],i+1<ans.size()?' ':'\n');

	return 0;
}
