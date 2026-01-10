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
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<double> G(n);
	rep(i,m){
		int u,v;
		double c; scanf("%d%d%lf",&u,&v,&c);
		add_directed_edge(G,u,v,c);
	}

	vector<double> curr(n,10),next(n);
	rep(t,100){
		fill(next.begin(),next.end(),0);
		rep(u,n){
			double sum=0;
			for(auto e:G[u]) sum+=e.wt;
			for(auto e:G[u]) next[e.to]+=(e.wt/sum)*curr[u];
		}
		copy(next.begin(),next.end(),curr.begin());
	}
	rep(u,n) printf("%.9f\n",curr[u]);

	return 0;
}
