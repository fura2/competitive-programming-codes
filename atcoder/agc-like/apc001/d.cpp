#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

vector<vector<int>> connected_components(const graph& G){
	int n=G.size();
	vector<vector<int>> res;
	vector<bool> vis(n);
	rep(u,n) if(!vis[u]) {
		vis[u]=true;
		res.emplace_back();
		queue<int> Q; Q.emplace(u);
		while(!Q.empty()){
			int v=Q.front(); Q.pop();
			res.back().emplace_back(v);
			for(int w:G[v]) if(!vis[w]) {
				vis[w]=true;
				Q.emplace(w);
			}
		}
	}
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(u,n) scanf("%d",&a[u]);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add_undirected_edge(G,u,v);
	}

	auto C=connected_components(G);
	int k=C.size();
	if(k==1)      return puts("0"),0;
	if(2*(k-1)>n) return puts("Impossible"),0;

	lint ans=0;
	priority_queue<int,vector<int>,greater<>> Q;
	rep(i,k){
		vector<int> tmp;
		for(int u:C[i]) tmp.emplace_back(a[u]);
		sort(tmp.begin(),tmp.end());
		ans+=tmp[0];
		for(int j=1;j<tmp.size();j++) Q.emplace(tmp[j]);
	}
	for(int i=k;i<2*(k-1);i++){
		ans+=Q.top(); Q.pop();
	}
	printf("%lld\n",ans);

	return 0;
}
