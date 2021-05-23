#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int m; cin>>m;
	int n=26;
	graph G(n);
	vector<bool> b(n);
	rep(i,m){
		string s; cin>>s;
		int u=s.front()-'a';
		int v=s.back()-'a';
		add_undirected_edge(G,u,v);
		b[u]=b[v]=true;
	}

	vector<vector<int>> CC;
	for(auto tmp:connected_components(G)){
		if(tmp.size()>=2 || b[tmp[0]]){
			CC.emplace_back(tmp);
		}
	}
	int k=CC.size();

	if(k==1){
		int odd=0;
		for(int u:CC[0]) if(G[u].size()%2==1) odd++;
		printf("%d\n",odd==0?0:(odd-2)/2);
		return 0;
	}

	int ans=k-1,odd=0;
	for(auto C:CC){
		int cnt=0;
		for(int u:C) if(G[u].size()%2==1) cnt++;
		if(cnt==0) odd++;
		else       odd+=cnt-1;
	}
	odd-=k-2;
	if(odd>0) ans+=(odd-2)/2;
	printf("%d\n",ans);

	return 0;
}
