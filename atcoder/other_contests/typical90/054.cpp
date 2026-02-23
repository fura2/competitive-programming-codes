#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int>> E(m);
	rep(i,m){
		int k; scanf("%d",&k);
		E[i].resize(k);
		rep(j,k) scanf("%d",&E[i][j]), E[i][j]--;
	}

	vector<vector<int>> G(n);
	rep(i,m) for(int v:E[i]) G[v].emplace_back(i);

	vector<int> d(n,-1);
	d[0]=0;
	vector<bool> vis(m);
	queue<int> Q; Q.emplace(0);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int i:G[u]) if(!vis[i]) {
			vis[i]=true;
			for(int v:E[i]) if(d[v]==-1) {
				d[v]=d[u]+1;
				Q.emplace(v);
			}
		}
	}
	rep(u,n) printf("%d\n",d[u]);

	return 0;
}
