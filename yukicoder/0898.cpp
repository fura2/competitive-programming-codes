#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

template<class T>
class lowest_common_ancestor{
	vector<int> dep;
	vector<vector<int>> par;
	const weighted_graph<T>& Tr;

	vector<vector<lint>> wt;

	void dfs(int u,int p,int d){
		dep[u]=d;
		par[0][u]=p;
		for(const auto& e:Tr[u]){
			if(e.to!=p) dfs(e.to,u,d+1);
			else wt[0][u]=e.wt;
		}
	}

public:
	lowest_common_ancestor(const weighted_graph<T>& Tr,int root):Tr(Tr){
		int n=Tr.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));
		wt.assign(h,vector<lint>(n));

		dfs(root,-1,0);
		rep(i,h-1) rep(u,n) if(par[i][u]!=-1) {
			par[i+1][u]=par[i][par[i][u]];
			wt[i+1][u]=wt[i][u]+wt[i][par[i][u]];
		}
	}

	int lca(int u,int v)const{
		int h=par.size();

		if(dep[u]>dep[v]) swap(u,v);
		rep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];
		if(u==v) return u;

		for(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];
		return par[0][u];
	}

	int dist(int u,int v)const{ return dep[u]+dep[v]-2*dep[lca(u,v)]; }

	lint solve(int u,int v)const{
		lint res=0;
		int w=lca(u,v);
		for(int i=int(wt.size())-1;i>=0;i--) if(dep[u]-(1<<i)>=dep[w]) {
			res+=wt[i][u];
			u=par[i][u];
		}
		for(int i=int(wt.size())-1;i>=0;i--) if(dep[v]-(1<<i)>=dep[w]) {
			res+=wt[i][v];
			v=par[i][v];
		}
		return res;
	}
};

int main(){
	int n; scanf("%d",&n);
	weighted_graph<lint> T(n);
	rep(i,n-1){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c);
		add_undirected_edge(T,u,v,c);
	}

	lowest_common_ancestor<lint> LCA(T,0);

	int q; scanf("%d",&q);
	rep(_,q){
		int u[3];
		rep(i,3) scanf("%d",&u[i]);

		sort(u,u+3,[&](int v,int w){
			return LCA.dist(0,v)<LCA.dist(0,w);
		});

		if(LCA.dist(u[0],u[1])+LCA.dist(u[1],u[2])==LCA.dist(u[0],u[2])){ // line
			printf("%lld\n",LCA.solve(u[0],u[2]));
		}
		else{ // Y
			int u01=LCA.lca(u[0],u[1]);
			int u02=LCA.lca(u[0],u[2]);
			int u12=LCA.lca(u[1],u[2]);
			int r=LCA.lca(u01,u02);

			lint ans=0;
			if(u01!=r){
				ans+=LCA.solve(u[0],u[1]);
				ans+=LCA.solve(u01,r);
				ans+=LCA.solve(u[2],r);
			}
			else if(u02!=r){
				ans+=LCA.solve(u[0],u[2]);
				ans+=LCA.solve(u02,r);
				ans+=LCA.solve(u[1],r);
			}
			else{
				ans+=LCA.solve(u[1],u[2]);
				ans+=LCA.solve(u12,r);
				ans+=LCA.solve(u[0],r);
			}
			printf("%lld\n",ans);
		}
	}

	return 0;
}
