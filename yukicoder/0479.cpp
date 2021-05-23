#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		add_undirected_edge(G,u,v);
	}

	string ans(n,'?');
	for(int u=n-1;u>=0;u--){
		bool need=false;
		for(int v:G[u]) if(ans[v]=='0') need=true;
		ans[u]=(need?'1':'0');
	}
	while(ans.length()>=2 && ans.back()=='0') ans.pop_back();
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';

	return 0;
}
