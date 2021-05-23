#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

int main(){
	int n; scanf("%d",&n);

	graph G(n);
	vector<int> deg(n);
	rep(i,n){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		deg[u]++;
		deg[v]++;
	}

	vector<bool> del(n);
	queue<int> Q;
	rep(u,n) if(deg[u]==1) {
		del[u]=true;
		Q.emplace(u);
	}
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(!del[v]) {
			deg[v]--;
			if(deg[v]==1){
				del[v]=true;
				Q.emplace(v);
			}
		}
	}
	printf("%ld\n",count(del.begin(),del.end(),false));

	return 0;
}
