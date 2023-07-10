#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;
using graph=vector<vector<int>>;

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
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	auto res=two_coloring(G);
	if(res.first){
		lint n1=count(res.second.begin(),res.second.end(),0);
		lint n2=count(res.second.begin(),res.second.end(),1);
		printf("%lld\n",n1*n2-m);
	}
	else{
		printf("%lld\n",n*(n-1LL)/2-m);
	}

	return 0;
}
