#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class bipartite_graph{
	int L,R;
	vector<vector<int>> G,match;
	vector<bool> vis;

	bool augment(int u){
		if(u==-1) return true;
		for(int v:G[u]) if(!vis[v]) {
			vis[v]=true;
			if(augment(match[1][v])){
				match[0][u]=v;
				match[1][v]=u;
				return true;
			}
		}
		return false;
	}

public:
	bipartite_graph(int L,int R):L(L),R(R),G(L){}

	void add_edge(int u,int v){ G[u].emplace_back(v); }

	const vector<int>& operator[](int u)const{ return G[u]; }

	pair<int,vector<vector<int>>> bipartite_matching(){
		match.resize(2);
		match[0].assign(L,-1);
		match[1].assign(R,-1);

		int res=0;
		vis.resize(R);
		rep(u,L){
			fill(vis.begin(),vis.end(),false);
			if(augment(u)) res++;
		}

		return {res,match};
	}
};

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector d(n,vector(n,INF));
	rep(u,n) d[u][u]=0;
	rep(i,m){
		int u,v;
		lint cost; scanf("%d%d%lld",&u,&v,&cost); u--; v--;
		d[u][v]=d[v][u]=min(d[u][v],cost);
	}

	rep(k,n) rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	int k; scanf("%d",&k);
	vector<int> a(k);
	rep(i,k) scanf("%d",&a[i]), a[i]--;

	int l; scanf("%d",&l);
	vector<int> b(l);
	rep(i,l) scanf("%d",&b[i]), b[i]--;

	lint lo=-1,hi=1e9*n;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		bipartite_graph G(k-1,l);
		int cnt=0;
		rep(i,k-1){
			if(d[a[i]][a[i+1]]<=mi){
				cnt++;
			}
			else{
				rep(j,l){
					if(d[b[j]][a[i+1]]<=mi){
						G.add_edge(i,j);
					}
				}
			}
		}
		(G.bipartite_matching().first+cnt==k-1?hi:lo)=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
