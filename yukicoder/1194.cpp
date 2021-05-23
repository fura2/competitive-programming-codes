#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

class strongly_connected_components{
	int idx;
	vector<int> top,id;
	const graph& G;
	graph G_rev;

	vector<vector<int>> Comp;
	graph D;

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
	strongly_connected_components(const graph& G):G(G){
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

		Comp.resize(idx);
		D.resize(idx);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(int v:G[u]) if(id[u]!=id[v]) D[id[u]].emplace_back(id[v]);
		}
	}

	int operator[](int i)const{ return id[i]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const graph& DAG()const{ return D; }
};

int main(){
	int N,m; scanf("%d%d",&N,&m);
	vector<int> a(m),b(m);
	vector<int> X;
	rep(i,m){
		scanf("%d%d",&a[i],&b[i]);
		X.emplace_back(a[i]);
		X.emplace_back(b[i]);
	}

	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	int n=X.size();
	graph G(n);
	rep(i,m){
		int u=lower_bound(X.begin(),X.end(),a[i])-X.begin();
		int v=lower_bound(X.begin(),X.end(),b[i])-X.begin();
		add_directed_edge(G,u,v);
	}

	strongly_connected_components SCC(G);
	auto D=SCC.DAG();
	int k=D.size();
	vector<int> dp(k);
	for(int i=k-1;i>=0;i--){
		for(int u:SCC.component(i)) dp[i]=max(dp[i],X[u]);
		for(int j:D[i]){
			dp[i]=max(dp[i],dp[j]);
		}
	}

	lint ans=lint(N)*(N+1)/2;
	rep(i,k){
		ans+=SCC.component(i).size()*dp[i];
		for(int u:SCC.component(i)) ans-=X[u];
	}
	printf("%lld\n",ans);

	return 0;
}
