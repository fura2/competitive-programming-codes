#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);

	graph G(n);
	vector<int> deg(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_directed_edge(G,u,v);
		deg[v]++;
	}

	vector<int> ans;
	bool b=false;

	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);

	while(!Q.empty()){
		if(Q.size()>=2) b=true;
		int u=Q.front(); Q.pop();
		ans.emplace_back(u);
		for(int v:G[u]){
			deg[v]--;
			if(deg[v]==0) Q.emplace(v);
		}
	}

	rep(i,n) printf("%d\n",ans[i]+1);
	puts(b?"1":"0");

	return 0;
}
