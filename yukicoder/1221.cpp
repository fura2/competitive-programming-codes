#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph T;
lint a[100000],b[100000];

bool vis[100000][2][2];
lint memo[100000][2][2];

// bu : u が消されずに残っているかどうか
// bp : p が消されずに残っているかどうか
lint dfs(int u,int p,bool bu,bool bp){
	lint& res=memo[u][bu][bp];
	if(vis[u][bu][bp]) return res;
	vis[u][bu][bp]=true;

	if(!bu){
		res=a[u];
		for(int v:T[u]) if(v!=p) {
			res+=max(dfs(v,u,false,false),dfs(v,u,true,false));
		}
	}
	else{
		res=(bp?b[u]:0);
		for(int v:T[u]) if(v!=p) {
			res+=max(dfs(v,u,false,true),dfs(v,u,true,true)+b[u]);
		}
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	rep(u,n) scanf("%lld",&a[u]);
	rep(u,n) scanf("%lld",&b[u]);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	printf("%lld\n",max(dfs(0,-1,false,false),dfs(0,-1,true,false)));

	return 0;
}
