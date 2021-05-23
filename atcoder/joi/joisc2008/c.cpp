// Day 1: Flu

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

vector<int> distance(const graph& G,int s){
	const int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int n,m,d,k; scanf("%d%d%d%d",&n,&m,&d,&k);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	vector B(1000,vector(1000,-1));
	rep(i,n) B[y[i]][x[i]]=i;

	graph G(n);
	rep(u,n){
		for(int i=y[u]-d;i<=y[u]+d;i++) for(int j=x[u]-d;j<=x[u]+d;j++) {
			if((j-x[u])*(j-x[u])+(i-y[u])*(i-y[u])<=d*d && 0<=i && i<1000 && 0<=j && j<1000){
				int v=B[i][j];
				if(v!=-1 && u<v) add_undirected_edge(G,u,v);
			}
		}
	}

	auto dist=distance(G,0);

	int ans=0;
	rep(u,n) if(dist[u]<INT_MAX && dist[u]<=k && k<dist[u]+m) ans++;
	printf("%d\n",ans);

	return 0;
}
