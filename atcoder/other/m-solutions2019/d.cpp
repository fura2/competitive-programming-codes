#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph T;
priority_queue<int> Q;
vector<int> ans;

void dfs(int u,int p){
	ans[u]=Q.top(); Q.pop();
	for(int v:T[u]) if(v!=p) dfs(v,u);
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	vector<int> wt(n);
	rep(u,n){
		scanf("%d",&wt[u]);
		Q.emplace(wt[u]);
	}

	ans.resize(n);
	dfs(0,-1);

	printf("%d\n",accumulate(wt.begin(),wt.end(),0)-*max_element(wt.begin(),wt.end()));
	rep(u,n) printf("%d%c",ans[u],u<n-1?' ':'\n');

	return 0;
}
