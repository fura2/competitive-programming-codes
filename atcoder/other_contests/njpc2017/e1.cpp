#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

int d_max;
weighted_graph<pair<int,int>> T;

const int INF=1<<29;

int dist[100000]; // dist[u] = (u を根とする部分木について, u から最も遠い頂点までの距離)
int ori[100000];  // ori[u] = (u を根とする部分木について, u から見て順方向の辺の本数)

void dfs1(int u,int p){
	for(const auto& e:T[u]) if(e.to!=p) {
		int v=e.to,cost=e.wt.first,o=e.wt.second;
		dfs1(v,u);
		dist[u]=max(dist[u],dist[v]+cost);
		ori[u]+=ori[v]+(o==0?1:0);
	}
}

int ans=INF;

void dfs2(int u,int p,int d_par,int o_par){
	if(max(dist[u],d_par)<=d_max){
		ans=min(ans,ori[u]+o_par);
	}

	vector<pair<int,int>> info={{0,-1}};
	for(const auto& e:T[u]) if(e.to!=p) {
		int v=e.to,cost=e.wt.first;
		info.emplace_back(dist[v]+cost,v);
	}
	int k=info.size();
	partial_sort(info.rbegin(),info.rbegin()+min(2,k),info.rend());

	for(const auto& e:T[u]) if(e.to!=p) {
		int v=e.to,cost=e.wt.first,o=e.wt.second;
		int d_other=info[info[0].second!=v?0:1].first;
		dfs2(v,u,max(d_par,d_other)+cost,o_par+ori[u]-ori[v]-(o==0?1:0)+(o==1?1:0));
	}
}

int main(){
	int n; scanf("%d%d",&n,&d_max);
	T.resize(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		T[u].emplace_back(v,make_pair(c,0));
		T[v].emplace_back(u,make_pair(c,1));
	}

	dfs1(0,-1);
	dfs2(0,-1,0,0);

	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
