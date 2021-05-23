#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

graph T;
string s;
lint ctotal,wtotal;

lint ccnt[100000],wcnt[100000];

lint dfs(int u,int p){
	lint res=0;
	if(s[u]=='c'){
		for(int v:T[u]) if(v!=p) {
			res+=dfs(v,u);
			ccnt[u]+=ccnt[v];
			wcnt[u]+=wcnt[v];
		}
		ccnt[u]++;
	}
	else{
		for(int v:T[u]) if(v!=p) {
			res+=dfs(v,u);
			res-=ccnt[v]*wcnt[v];
			ccnt[u]+=ccnt[v];
			wcnt[u]+=wcnt[v];
		}
		res+=ctotal*(wtotal-1);
		res-=(ctotal-ccnt[u])*(wtotal-wcnt[u]-1);
		wcnt[u]++;
	}
	return res;
}

int main(){
	int n; cin>>n>>s;
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	rep(i,n){
		if(s[i]=='c') ctotal++;
		if(s[i]=='w') wtotal++;
	}

	cout<<dfs(0,-1)<<'\n';

	return 0;
}
