#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class strongly_connected_components{
	int idx;
	vector<int> top,id;
	const vector<vector<int>>& G;
	vector<vector<int>> G_rev;

	void dfs1(int u){
		id[u]=0;
		for(int v:G[u]) if(id[v]==-1) dfs1(v);
		top[idx++]=u;
	}

	void dfs2(int u){
		id[u]=idx;
		for(int v:G_rev[u]) if(id[v]==-1) dfs2(v);
	}

public:
	vector<vector<int>> DAG;

	strongly_connected_components(const vector<vector<int>>& G):G(G){
		int n=G.size();
		G_rev.resize(n);
		rep(u,n) for(int v:G[u]) G_rev[v].emplace_back(u);

		idx=0;
		id.assign(n,-1);
		top.resize(n);
		rep(u,n) if(id[u]==-1) dfs1(u);

		reverse(top.begin(),top.end());

		idx=0;
		id.assign(n,-1);
		for(int u:top) if(id[u]==-1) dfs2(u), idx++;

		DAG.resize(idx);
		rep(u,n) for(int v:G[u]) if(id[u]!=id[v]) DAG[id[u]].emplace_back(id[v]);
	}

	int operator[](int i)const{ return id[i]; }
};

vector<vector<int>> H; // DAG
vector<vector<bool>> H_bar; // H_bar : transitive closure of H
vector<int> weight;

int memo[300][300];

int dfs(int i,int j){
	if(~memo[i][j]) return memo[i][j];

	int res=(i==j?weight[i]:weight[i]+weight[j]);

	if(i!=j){
		if(!H_bar[j][i]){
			for(int k:H[i]) res=max(res,dfs(k,j)+weight[i]);
		}
		if(!H_bar[i][j]){
			for(int k:H[j]) res=max(res,dfs(i,k)+weight[j]);
		}
	}
	else{ // i==j
		for(int k:H[i]) res=max(res,dfs(i,k));
	}

	return memo[i][j]=res;
}

int main(){
	int n; cin>>n;
	vector<vector<int>> G(n);
	rep(u,n) rep(v,n) {
		int a; cin>>a;
		if(a==1) G[u].emplace_back(v);
	}

	strongly_connected_components SCC(G);
	H=SCC.DAG;

	int m=H.size();
	weight.assign(m,0);
	rep(u,n) weight[SCC[u]]++;

	H_bar.assign(m,vector<bool>(m));
	rep(i,m) for(int j:H[i]) H_bar[i][j]=true;
	rep(k,m) rep(i,m) rep(j,m) if(H_bar[i][k] && H_bar[k][j]) H_bar[i][j]=true;

	memset(memo,-1,sizeof memo);

	int ans=0;
	rep(i,m) rep(j,m) ans=max(ans,dfs(i,j));
	cout<<ans<<endl;

	return 0;
}
