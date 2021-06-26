#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

pair<bool,vector<int>> two_coloring(const graph& G){
	int n=G.size();
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		color[u]=0;
		queue<int> Q; Q.emplace(u);
		while(!Q.empty()){
			int v=Q.front(); Q.pop();
			for(int w:G[v]){
				if(color[w]==-1){
					color[w]=1-color[v];
					Q.emplace(w);
				}
				else if(color[w]==color[v]) return {false,vector<int>()};
			}
		}
	}
	return {true,color};
}

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	vector<int> res[2];
	auto C=two_coloring(T).second;
	rep(u,n){
		res[C[u]].emplace_back(u);
	}

	int idx=(res[0].size()>res[1].size()?0:1);
	rep(i,n/2) printf("%d%c",res[idx][i]+1,i<n/2-1?' ':'\n');

	return 0;
}
