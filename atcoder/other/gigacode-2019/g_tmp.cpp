#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;
using graph=vector<vector<int>>;

lint subtask2(const graph& G){
	int n=G.size();
	lint res=0;
	rep(s,n){
		vector<int> d(n,-1);
		d[s]=0;
		queue<int> Q; Q.emplace(s);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			for(int v:G[u]) if(d[v]==-1) {
				d[v]=d[u]+1;
				Q.emplace(v);
			}
		}
		rep(u,n) res+=d[u];
	}
	return res/2;
}

int sz[100000];
int dfs3(int u,int p,const graph& T){
	sz[u]=1;
	for(int v:T[u]) if(v!=p) {
		sz[u]+=dfs3(v,u,T);
	}
	return sz[u];
}

lint memo2[100000];
lint dfs2(int u,int p,const graph& T){
	if(memo2[u]!=-1) return memo2[u];

	lint res=0;
	for(int v:T[u]) if(v!=p) {
		res+=dfs2(v,u,T)+sz[v];
	}
	return memo2[u]=res;
}

lint dfs1(int u,int p,const graph& T){
	lint res=dfs2(u,p,T);
	for(int v:T[u]) if(v!=p) {
		res+=dfs1(v,u,T);
		res+=(sz[u]-sz[v]-1)*(dfs2(v,u,T)+sz[v]);
	}
	return res;
}

lint subtask3(const graph& T){
	int n=T.size();
	rep(u,n) memo2[u]=-1;
	dfs3(0,-1,T);
	dfs2(0,-1,T);
	return dfs1(0,-1,T);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	lint res;
	if     (m<=3000) res=subtask2(G);
	else if(m==n-1)  res=subtask3(G);
	else res=-1;
	printf("%lld\n",res);

	return 0;
}
