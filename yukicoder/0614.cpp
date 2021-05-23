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
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
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
	int n,m,s,t; scanf("%d%d%*d%d%d",&n,&m,&s,&t); s--; t--;
	map<pair<int,int>,int> f;
	f[{0,s}]=0;
	f[{n-1,t}]=1;
	weighted_graph<lint> G(2);
	rep(i,m){
		int a,b,c; scanf("%d%d%d",&a,&b,&c); a--; b--; c--;
		if(f.count({a,b})==0)   f[{a,b}]=f.size();
		if(f.count({a+1,c})==0) f[{a+1,c}]=f.size();
		int u=f[{a,b}],v=f[{a+1,c}];
		G.resize(f.size());
		add_directed_edge(G,u,v,0LL);
	}
	for(auto it=f.begin();it!=f.end();++it){
		auto jt=it;
		++jt;
		if(jt==f.end()) continue;
		auto [a1,b1]=it->first;
		auto [a2,b2]=jt->first;
		if(a1==a2){
			add_undirected_edge(G,it->second,jt->second,lint(abs(b1-b2)));
		}
	}

	lint ans=Dijkstra(G,f[{0,s}])[f[{n-1,t}]];
	printf("%lld\n",ans<LLONG_MAX?ans:-1);

	return 0;
}
