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

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> val(n);
	rep(u,n) scanf("%lld",&val[u]);

	map<pair<int,int>,int> E;
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		if(u>v) swap(u,v);
		++E[{u,v}];
	}

	lint ans=0;
	// 自己ループを削除
	for(auto it=E.begin();it!=E.end();){
		auto [u,v]=it->first;
		if(u==v){
			ans+=val[u];
			val[u]=0;
			it=E.erase(it);
		}
		else{
			++it;
		}
	}
	// 多重辺を削除
	for(auto it=E.begin();it!=E.end();){
		auto [u,v]=it->first;
		if(it->second>=2){
			ans+=val[u]+val[v];
			val[u]=val[v]=0;
			it=E.erase(it);
		}
		else{
			++it;
		}
	}

	graph G(n);
	for(auto p:E){
		auto [u,v]=p.first;
		add_undirected_edge(G,u,v);
	}
	for(auto C:connected_components(G)){
		int cnt=0;
		lint sum=0,mn=INF;
		for(int u:C){
			cnt+=G[u].size();
			sum+=val[u];
			mn=min(mn,val[u]);
		}

		if(cnt/2==C.size()-1){ // 木
			ans+=sum-mn;
		}
		else{
			ans+=sum;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
