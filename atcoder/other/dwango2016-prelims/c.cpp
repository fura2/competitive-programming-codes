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
	priority_queue<pair<T,int>,vector<pair<T,int>>,greater<>> Q;
	Q.emplace(0,s);
	while(!Q.empty()){
		T d0;
		int u; tie(d0,u)=Q.top();
		Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(d[v],v);
			}
		}
	}
	return d;
}

const long long INF=1LL<<61;

int main(){
	int n,m,s,t; scanf("%d%d%d%d",&n,&m,&s,&t);
	weighted_graph<lint> G(n);
	weighted_graph<tuple<lint,int,lint>> H(n); // (有向辺の長さ, その有向辺で寝過ごしたときの終点, 終点までの距離)
	rep(i,m){
		int l; scanf("%d",&l);
		vector<int> V(l);
		vector<lint> C(l-1);
		lint sum=0;
		rep(j,l) scanf("%d",&V[j]);
		rep(j,l-1) scanf("%lld",&C[j]), sum+=C[j];

		lint tmp=sum;
		rep(j,l-1){
			add_undirected_edge(G,V[j],V[j+1],C[j]);
			add_directed_edge(H,V[j],V[j+1],make_tuple(C[j],V[l-1],tmp));
			tmp-=C[j];
		}
		tmp=sum;
		for(int j=l-1;j>0;j--){
			add_directed_edge(H,V[j],V[j-1],make_tuple(C[j-1],V[0],tmp));
			tmp-=C[j-1];
		}
	}

	auto d_t=Dijkstra(G,t);

	lint lo=0,hi=1e9;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		vector<lint> d(n,INF);
		d[s]=0;
		priority_queue<pair<lint,int>,vector<pair<lint,int>>,greater<>> Q;
		Q.emplace(0,s);
		while(!Q.empty()){
			lint d0;
			int u; tie(d0,u)=Q.top(); Q.pop();
			if(d0>d[u]) continue;

			for(auto e:H[u]){
				int v=e.to,w;
				lint cost1,cost2; tie(cost1,w,cost2)=e.wt;
				if(d[u]+cost2+d_t[w]<=mi && d[u]+cost1<d[v]){
					d[v]=d[u]+cost1;
					Q.emplace(d[v],v);
				}
			}
		}
		if(d[t]<INF) hi=mi;
		else         lo=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
