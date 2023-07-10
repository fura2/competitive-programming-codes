#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

const long long INF=1LL<<61;

int n;
graph T;
vector<lint> a;

vector<int> sz;
// res1[u][i] = (頂点 u を根とする部分木について, i 本の辺を切って,
//               u を含む連結成分に含まれるすべての頂点 v が A_v>0 をみたすときの,
//               u を含む連結成分に含まれる A_v の和の最小値)
// res2[u][i] = (頂点 u を根とする部分木について, i 本の辺を切って,
//               u を含む連結成分に含まれるある頂点 v が A_v<0 をみたすときの,
//               u を含む連結成分に含まれる A_v の和の最小値)
vector<vector<lint>> res1,res2;

void dfs(int u,int p){
	sz[u]=1;
	if(a[u]>0) res1[u][0]=a[u];
	else       res2[u][0]=a[u];

	for(int v:T[u]) if(v!=p) {
		dfs(v,u);

		vector<lint> tmp1(sz[u]+sz[v],INF);
		vector<lint> tmp2(sz[u]+sz[v],INF);
		// 辺 (u,v) を切る
		rep(i,sz[u]) rep(j,sz[v]) {
			if(res1[v][j]<INF || res2[v][j]<0){
				tmp1[i+j+1]=min(tmp1[i+j+1],res1[u][i]);
				tmp2[i+j+1]=min(tmp2[i+j+1],res2[u][i]);
			}
		}
		// 辺 (u,v) を残す
		rep(i,sz[u]) rep(j,sz[v]) {
			if(res1[u][i]<INF && res1[v][j]<INF){
				tmp1[i+j]=min(tmp1[i+j],res1[u][i]+res1[v][j]);
			}
			if(res1[u][i]<INF && res2[v][j]<INF){
				tmp2[i+j]=min(tmp2[i+j],res1[u][i]+res2[v][j]);
			}
			if(res2[u][i]<INF && res1[v][j]<INF){
				tmp2[i+j]=min(tmp2[i+j],res2[u][i]+res1[v][j]);
			}
			if(res2[u][i]<INF && res2[v][j]<INF){
				tmp2[i+j]=min(tmp2[i+j],res2[u][i]+res2[v][j]);
			}
		}

		sz[u]+=sz[v];
		res1[u]=tmp1;
		res2[u]=tmp2;
	}
}

int main(){
	scanf("%d",&n);
	a.resize(n);
	T.resize(n);
	rep(u,n) scanf("%lld",&a[u]);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	sz.assign(n,0);
	res1.assign(n,vector<lint>(n,INF));
	res2.assign(n,vector<lint>(n,INF));
	dfs(0,-1);

	rep(i,n){
		if(res1[0][i]!=INF || res2[0][i]<0){
			printf("%d\n",i);
			return 0;
		}
	}
	abort();

	return 0;
}
