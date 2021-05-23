#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double INF=1e77;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
pair<T,weighted_graph<T>> Kruskal(const weighted_graph<T>& G){
	int n=G.size();
	vector<tuple<T,int,int>> E;
	rep(u,n) for(const auto& e:G[u]) {
		int v=e.to;
		if(u<v) E.emplace_back(e.wt,u,v);
	}

	sort(E.begin(),E.end());

	T ans{};
	weighted_graph<T> Res(n);
	union_find U(n);
	for(const auto& e:E){
		if(U.size()==1) break;
		T wt;
		int u,v; tie(wt,u,v)=e;
		if(!U.is_same(u,v)){
			U.unite(u,v);
			ans+=wt;
			Res[u].emplace_back(v,wt);
			Res[v].emplace_back(u,wt);
		}
	}
	return {ans,Res};
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int x[35],y[35],c[35];
	rep(i,n+m) scanf("%d%d%d",&x[i],&y[i],&c[i]);

	double ans=INF;
	rep(S,1<<m){
		weighted_graph<double> G(n+m);
		rep(i,n+m) rep(j,n+m) if((i<n || (S>>(i-n)&1)) && (j<n || (S>>(j-n)&1))) {
			double cost=(c[i]==c[j]?1:10)*hypot(x[i]-x[j],y[i]-y[j]);
			G[i].emplace_back(j,cost);
			G[j].emplace_back(i,cost);
		}
		ans=min(ans,Kruskal(G).first);
	}
	printf("%.9f\n",ans);

	return 0;
}
