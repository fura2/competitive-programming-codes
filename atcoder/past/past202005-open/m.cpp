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

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}
	int s,k; scanf("%d%d",&s,&k); s--;
	vector<int> t(k+1);
	t[0]=s;
	rep(i,k) scanf("%d",&t[i+1]), t[i+1]--;
	k++;

	vector<vector<int>> d(k);
	rep(i,k) d[i]=distance(G,t[i]);

	static int dp[1<<17][17];
	rep(S,1<<k) rep(u,k) dp[S][u]=INF;
	dp[1][0]=0;
	rep(S,1<<k) rep(u,k) if(S>>u&1) {
		rep(v,k) if((S>>v&1)==0) {
			dp[S|1<<v][v]=min(dp[S|1<<v][v],dp[S][u]+d[u][t[v]]);
		}
	}
	printf("%d\n",*min_element(dp[(1<<k)-1],dp[(1<<k)-1]+k));

	return 0;
}
