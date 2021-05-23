#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int idx;
vector<int> ans;

// 完全二分木を少しだけ変形した木に inorder で番号をつける
void dfs(const graph& T,int u,int p){
	int l=-1,r=-1;
	for(int v:T[u]) if(v!=p) {
		if     (l==-1) l=v;
		else if(r==-1) r=v;
	}

	if(l!=-1) dfs(T,l,u);
	ans[u]=idx++;
	if(r!=-1) dfs(T,r,u);
}

int main(){
	int k; scanf("%d",&k);
	int n=(1<<k)-1;
	graph T(n);
	rep(u,n/2  ) add_edge(T,u,2*u+1);
	rep(u,n/2-1) add_edge(T,u,2*u+2);
	add_edge(T,n-2,n-1);

	ans.resize(n);
	dfs(T,0,-1);

	rep(u,n) printf("%d%c",ans[u]+1,u<n-1?' ':'\n');

	return 0;
}
