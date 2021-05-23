#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int V_MAX=40;

class maximum_independent_set_solver{
	int n,deg[V_MAX];
	vector<int> G[V_MAX];

	int ans;
	bool vis[V_MAX];
	void dfs(int u,int now){
		int rem=count(vis+u,vis+n,false);
		if(now+rem<=ans) return;
		ans=max(ans,now);
		if(rem==0) return;
		if(vis[u]){ dfs(u+1,now); return; }

		{
			bool tmp[V_MAX];
			rep(v,n) tmp[v]=vis[v];
			rep(i,G[u].size()){ int v=G[u][i]; deg[v]--; vis[v]=true; }
			vis[u]=true;
			dfs(u+1,now+1);
			rep(i,G[u].size()){ int v=G[u][i]; deg[v]++; }
			rep(v,n) vis[v]=tmp[v];
		}
		if(deg[u]>1){
			vis[u]=true;
			dfs(u+1,now);
			vis[u]=false;
		}
	}

public:
	int solve(int n_in,const vector<int> *G_in){
		n=n_in;
		rep(u,n){
			G[u]=G_in[u];
			deg[u]=G[u].size();
			vis[u]=false;
		}
		ans=0;
		dfs(0,0);
		return ans;
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> G[40];
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	maximum_independent_set_solver S;
	printf("%d\n",S.solve(n,G));

	return 0;
}
