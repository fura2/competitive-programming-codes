#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

bool is_DAG(const graph& G){
	int n=G.size();
	vector<int> deg(n);
	rep(u,n) for(int v:G[u]) deg[v]++;

	int cnt=0;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		cnt++;
		for(int v:G[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return cnt==n;
}

vector<int> topological_order(const graph& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(int v:D[u]) deg[v]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(int v:D[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);

	int m=5e5;
	graph G(n+m);
	rep(i,n){
		int k; scanf("%d",&k);
		rep(j,k){
			int a; scanf("%d",&a); a--;
			add_directed_edge(G,n+a,i);
		}
		scanf("%d",&k);
		rep(j,k){
			int b; scanf("%d",&b); b--;
			add_directed_edge(G,i,n+b);
		}
	}

	if(!is_DAG(G)){
		puts("-1");
		return 0;
	}

	vector<int> ans;
	for(int u:topological_order(G)) if(u<n) ans.emplace_back(u);
	rep(i,n) printf("%d%c",ans[i]+1,i<n-1?' ':'\n');

	return 0;
}
