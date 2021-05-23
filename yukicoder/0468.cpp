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
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_directed_edge(G,u,v,c);
	}

	auto p=topological_order(G);

	vector<int> dp(n);
	for(int u:p){
		for(auto e:G[u]) dp[e.to]=max(dp[e.to],dp[u]+e.wt);
	}

	vector<bool> ok(n);
	ok[n-1]=true;
	rep(i,n){
		int u=p[n-1-i];
		for(auto e:G[u]) if(ok[e.to] && dp[e.to]==dp[u]+e.wt) ok[u]=true;
	}
	printf("%d %ld/%d\n",dp[n-1],count(ok.begin(),ok.end(),false),n);

	return 0;
}
