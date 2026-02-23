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
	int n1,m1; scanf("%d%d",&n1,&m1);
	graph G1(n1);
	rep(i,m1){
		int u,v; scanf("%d%d",&u,&v);
		add_undirected_edge(G1,u,v);
	}
	int n2,m2; scanf("%d%d",&n2,&m2);
	graph G2(n2);
	rep(i,m2){
		int u,v; scanf("%d%d",&u,&v);
		add_undirected_edge(G2,u,v);
	}

	vector<int> d1(n1),d2(n2);
	rep(u,n1){
		auto d=distance(G1,u);
		rep(v,n1) if(v!=u) {
			d1[u]=max(d1[u],d[v]);
		}
	}
	rep(u,n2){
		auto d=distance(G2,u);
		rep(v,n2) if(v!=u) {
			d2[u]=max(d2[u],d[v]);
		}
	}

	int diam1=*max_element(d1.begin(),d1.end());
	int diam2=*max_element(d2.begin(),d2.end());

	int ans_max=0,ans_min=INF;
	rep(u,n1) rep(v,n2) {
		ans_max=max(ans_max,d1[u]+1+d2[v]);
		ans_min=min(ans_min,d1[u]+1+d2[v]);
	}
	ans_min=max({ans_min,diam1,diam2});
	printf("%d %d\n",ans_min,ans_max);

	return 0;
}
