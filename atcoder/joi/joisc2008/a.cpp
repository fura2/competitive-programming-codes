// Day 1: Committee

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

graph T;
vector<int> val,memo;

void dfs(int u){
	memo[u]=val[u];
	for(int v:T[u]){
		dfs(v);
		if(memo[v]>0) memo[u]+=memo[v];
	}
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	val.resize(n);
	rep(u,n){
		int p; scanf("%d%d",&p,&val[u]); p--;
		if(p!=-1) add_directed_edge(T,p,u);
	}

	memo.resize(n);
	dfs(0);

	printf("%d\n",*max_element(memo.begin(),memo.end()));

	return 0;
}
