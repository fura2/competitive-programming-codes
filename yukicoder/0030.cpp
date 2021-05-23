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
vector<int> topological_order(const weighted_graph<T>& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(const auto& e:D[u]) deg[e.to]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(const auto& e:D[u]) if(--deg[e.to]==0) Q.emplace(e.to);
	}
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&c,&v); u--; v--;
		G[u].emplace_back(v,c);
	}

	auto ord=topological_order(G);
	reverse(ord.begin(),ord.end());

	vector<lint> ans(n);
	vector<bool> leaf(n,true);
	ans[n-1]=1;
	for(int u:ord) for(const auto& e:G[u]) {
		ans[u]+=ans[e.to]*e.wt;
		leaf[e.to]=false;
	}
	rep(u,n-1) printf("%lld\n",leaf[u]?ans[u]:0LL);

	return 0;
}
