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
void add_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

int n;
weighted_graph<int> T;
vector<int> sz;

lint dfs(int u,int p){
	sz[u]=1;
	lint res=0;
	for(auto e:T[u]) if(e.to!=p) {
		int v=e.to;
		res+=dfs(v,u)+2LL*e.wt*sz[v]*(n-sz[v]);
		sz[u]+=sz[v];
	}
	return res;
}

int main(){
	scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_edge(T,u,v,c);
	}

	sz.resize(n);
	printf("%lld\n",dfs(0,-1));

	return 0;
}
