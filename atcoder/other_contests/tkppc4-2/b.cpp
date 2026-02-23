#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

graph T;
vector<bool> a,b;

bool dfs(int u,int p){
	b[u]=a[u];
	for(int v:T[u]) if(v!=p) {
		if(dfs(v,u)) b[u]=true;
	}
	return b[u];
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	a.resize(n);
	rep(i,m){
		int x; scanf("%d",&x); x--;
		a[x]=true;
	}

	int root=-1;
	rep(u,n) if(a[u]) root=u;
	b.resize(n);
	dfs(root,-1);

	vector<int> deg(n);
	rep(u,n) for(int v:T[u]) if(b[u] && b[v]) deg[v]++;

	vector<int> hist(n);
	rep(u,n) if(b[u]) hist[deg[u]]++;

	int N=count(b.begin(),b.end(),true);
	puts(hist[1]==2&&hist[2]==N-2?"Yes":"trumpet");

	return 0;
}
