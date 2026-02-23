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

vector<int> distance(const graph& G,int s){
	const int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

random_device seed_gen;
mt19937 rng(seed_gen());

// largest-first heuristics
vector<int> solve1(graph G){
	int n=G.size();

	vector<int> cnt1(n),cnt2(n);
	rep(u,n){
		auto d=distance(G,u);
		rep(v,n){
			if(d[v]<=1) cnt1[u]++;
			if(d[v]<=2) cnt2[u]++;
		}
	}

	vector<int> order(n);
	iota(order.begin(),order.end(),0);
	sort(order.begin(),order.end(),[&](int u,int v){
		return make_pair(cnt1[u],cnt2[u])>make_pair(cnt1[v],cnt2[v]);
	});

	vector<int> color(n,-1);

	auto dfs=[&](auto&& dfs,int i)->bool{
		if(i==n) return true;

		int u=order[i];
		bool used[4]={};
		for(int v:G[u]) if(color[v]!=-1) used[color[v]]=true;

		rep(c,4) if(!used[c]) {
			color[u]=c;
			if(dfs(dfs,i+1)) return true;
			color[u]=-1;
		}
		return false;
	};
	dfs(dfs,0);

	return color;
}

// smallest-last heuristics
vector<int> solve2(graph G){
	int n=G.size();

	vector<int> order(n); // smallest-last ordering (次数最小の頂点を選んで削除, を n 回繰り返す)
	vector<bool> used(n);
	rep(i,n){
		graph H(n);
		rep(u,n) for(int v:G[u]) {
			if(!used[u] && !used[v] && u<v){
				add_undirected_edge(H,u,v);
			}
		}

		int u=-1;
		rep(v,n) if(!used[v]) {
			if(u==-1 || H[u].size()>H[v].size()){
				u=v;
			}
		}
		order[n-i-1]=u;
		used[u]=true;
	}

	vector<int> color(n,-1);

	auto dfs=[&](auto&& dfs,int i)->bool{
		if(i==n) return true;

		int u=order[i];
		bool used[4]={};
		for(int v:G[u]) if(color[v]!=-1) used[color[v]]=true;

		rep(c,4) if(!used[c]) {
			color[u]=c;
			if(dfs(dfs,i+1)) return true;
			color[u]=-1;
		}
		return false;
	};
	dfs(dfs,0);

	return color;
}

// saturation heuristics
vector<int> solve3(graph G){
	int n=G.size();

	vector<int> color(n,-1);

	auto dfs=[&](auto&& dfs,int i)->bool{
		if(i==n) return true;

		// まだ選んでいない頂点の中から degree of saturation が最大のものを選ぶ (頂点の次数で tie break)
		int u=-1,sdeg=-1;
		rep(v,n) if(color[v]==-1) {
			bool used[4]={};
			for(int w:G[v]) if(color[w]!=-1) used[color[w]]=true;
			int tmp=count(used,used+4,true);
			if(tmp>sdeg || (tmp==sdeg && G[v].size()>G[u].size())){
				u=v;
				sdeg=tmp;
			}
		}

		bool used[4]={};
		for(int v:G[u]) if(color[v]!=-1) used[color[v]]=true;

		rep(c,4) if(!used[c]) {
			color[u]=c;
			if(dfs(dfs,i+1)) return true;
			color[u]=-1;
		}
		return false;
	};
	dfs(dfs,0);

	return color;
}

// smallest-last + randomized Kempe interchange impasse resolution
// (Morgenstern and Shapiro, Heuristics for Rapidly Four-Coloring Large Planar Graphs, 1991)
vector<int> solve4(graph G){
	int n=G.size();

	vector<int> order(n); // smallest-last ordering (次数最小の頂点を選んで削除, を n 回繰り返す)
	vector<bool> used(n);
	rep(i,n){
		graph H(n);
		rep(u,n) for(int v:G[u]) {
			if(!used[u] && !used[v] && u<v){
				add_undirected_edge(H,u,v);
			}
		}

		int u=-1;
		rep(v,n) if(!used[v]) {
			if(u==-1 || H[u].size()>H[v].size()){
				u=v;
			}
		}
		order[n-i-1]=u;
		used[u]=true;
	}

	vector<int> color(n,-1);

	auto Kempe=[&](int u){
		rep(_,100){
			vector<int> nbd;
			for(int v:G[u]) if(color[v]!=-1) nbd.emplace_back(v);
			shuffle(nbd.begin(),nbd.end(),rng);

			for(int v:nbd){
				rep(c1,4){
					int c0=color[v];
					if(c1!=c0){
						// v を含む c0-c1 chain の色を反転
						vector<pair<int,int>> S={{v,c0}};
						color[v]=-2;
						queue<int> Q; Q.emplace(v);
						while(!Q.empty()){
							int w=Q.front(); Q.pop();
							for(int z:G[w]) if(color[z]==c0 || color[z]==c1) {
								S.emplace_back(z,color[z]);
								color[z]=-2;
								Q.emplace(z);
							}
						}
						for(auto [w,c]:S) color[w]=(c==c0?c1:c0);
					}

					bool used[4]={};
					for(int w:nbd) used[color[w]]=true;
					rep(c2,4) if(!used[c2]) {
						color[u]=c2;
						return true;
					}
				}
			}
		}
		return false;
	};

	auto dfs=[&](auto&& dfs,int i)->bool{
		if(i==n) return true;

		int u=order[i];
		bool used[4]={};
		for(int v:G[u]) if(color[v]!=-1) used[color[v]]=true;

		rep(c,4) if(!used[c]) {
			color[u]=c;
			if(dfs(dfs,i+1)) return true;
			color[u]=-1;
		}
		if(Kempe(u)){
			if(dfs(dfs,i+1)) return true;
			color[u]=-1;
		}
		return false;
	};
	dfs(dfs,0);

	return color;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v);
	}

	vector<int> ans(n,-1);
	for(auto C:connected_components(G)){
		int N=C.size();
		map<int,int> f; // vertex -> id
		rep(i,N) f[C[i]]=i;

		graph H(N);
		for(int u:C) for(int v:G[u]) {
			int i=f[u],j=f[v];
			if(i<j) add_undirected_edge(H,i,j);
		}

//		auto color=solve1(H);
//		auto color=solve2(H);
//		auto color=solve3(H);
		auto color=solve4(H);
		rep(i,N) ans[C[i]]=color[i];
	}
	rep(u,n) printf("%d\n",ans[u]+1);

	return 0;
}
