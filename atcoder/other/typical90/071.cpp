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

graph G;
vector<int> deg;

int k;
vector<vector<int>> ans;

void dfs(int u,vector<int>& seq,set<int>& S){
	int n=G.size()-1;

	if(seq.size()==n){
		ans.emplace_back(seq);
		if(ans.size()==k){
			rep(i,k) rep(j,n) {
				printf("%d%c",ans[i][j]+1,j<n-1?' ':'\n');
			}
			exit(0);
		}
		return;
	}

	for(int v:G[u]){
		deg[v]--;
		if(deg[v]==0) S.emplace(v);
	}
	for(auto it=S.begin();it!=S.end();){
		int v=*it;
		S.erase(it);
		seq.emplace_back(v);
		dfs(v,seq,S);
		seq.pop_back();
		S.emplace(v);
		it=next(S.find(v));
	}
	for(int v:G[u]){
		if(deg[v]==0) S.erase(v);
		deg[v]++;
	}
}

int main(){
	int n,m; scanf("%d%d%d",&n,&m,&k);
	G.resize(n+1);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_directed_edge(G,u,v);
	}
	rep(u,n) add_directed_edge(G,n,u);

	if(!is_DAG(G)){
		puts("-1");
		return 0;
	}

	deg.resize(n+1);
	rep(u,n+1) for(int v:G[u]) deg[v]++;

	vector<int> seq;
	set<int> S; // set of next vertices
	dfs(n,seq,S);

	puts("-1");

	return 0;
}
