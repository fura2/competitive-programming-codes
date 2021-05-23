#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,par[10000],sz[10000];

int find(int u){
	return par[u]==u?u:par[u]=find(par[u]);
}

int main(){
	int m; scanf("%d%d",&n,&m);
	rep(u,n){
		par[u]=u;
		sz[u]=1;
	}
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		u=find(u);
		v=find(v);
		if(u==v) continue;
		if(sz[u]>sz[v] || (sz[u]==sz[v] && u<v)){
			par[v]=u;
			sz[u]+=sz[v];
		}
		else{
			par[u]=v;
			sz[v]+=sz[u];
		}
	}

	rep(u,n) printf("%d\n",find(u)+1);

	return 0;
}
