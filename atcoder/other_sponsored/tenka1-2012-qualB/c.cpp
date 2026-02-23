#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

const int INF=1<<29;

int n;
graph G;

int color[15];

int dfs(int u,int c_max){
	if(u==n) return c_max;

	bool used[15]={};
	for(int v:G[u]) if(color[v]!=-1) used[color[v]]=true;

	int res=INF;
	rep(c,c_max+1) if(!used[c]) {
		color[u]=c;
		res=min(res,dfs(u+1,c<c_max?c_max:c_max+1));
		color[u]=-1;
	}
	return res;
}

int main(){
	scanf("%d",&n);
	vector<int> l(n),r(n);
	rep(u,n){
		int h1,m1,h2,m2; scanf("%d:%d%d:%d",&h1,&m1,&h2,&m2);
		l[u]=h1*60+m1;
		r[u]=h2*60+m2;
	}

	auto intersect=[](int l1,int r1,int l2,int r2){
		return l1<r2 && l2<r1;
	};

	G.resize(n);
	rep(u,n) for(int v=u+1;v<n;v++) {
		if(intersect(l[u],r[u],l[v],r[v])
		|| intersect(l[u],r[u],l[v]+1440,r[v]+1440)
		|| intersect(l[u],r[u],l[v]-1440,r[v]-1440)){
			add_undirected_edge(G,u,v);
		}
	}

	rep(u,n) color[u]=-1;
	printf("%d\n",dfs(0,0));

	return 0;
}
