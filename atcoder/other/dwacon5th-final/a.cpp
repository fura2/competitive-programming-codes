#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;
using lint=long long;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n,m;
	lint k;
	string s; cin>>n>>m>>k>>s;
	graph G(n);
	rep(i,m){
		int u,v; cin>>u>>v; u--; v--;
		add_undirected_edge(G,u,v);
	}

	vector<bool> good(n,true);
	rep(u,n){
		for(int v:G[u]) if(s[v]=='R') good[u]=false;
	}

	if(k%2==0){
		rep(u,n){
			bool ok=false;
			for(int v:G[u]) if(good[v]) ok=true;
			puts(ok?"First":"Second");
		}
	}
	else{
		rep(u,n){
			bool ok=false;
			for(int v:G[u]) if(s[v]=='B') ok=true;
			puts(ok?"First":"Second");
		}
	}

	return 0;
}
