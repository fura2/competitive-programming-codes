#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

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

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	weighted_graph<lint> G(h+w);
	rep(i,n){
		int y,x;
		lint a; scanf("%d%d%lld",&y,&x,&a); y--; x--;
		add_undirected_edge(G,y,h+x,a);
	}

	vector<lint> val(h+w);
	vector<bool> vis(h+w);
	rep(u,h+w) if(!vis[u]) {
		vis[u]=true;
		val[u]=0;

		lint row_min=INF,col_min=INF;
		queue<int> Q; Q.emplace(u);
		while(!Q.empty()){
			int v=Q.front(); Q.pop();

			if(v<h) row_min=min(row_min,val[v]);
			else    col_min=min(col_min,val[v]);

			for(auto e:G[v]){
				if(!vis[e.to]){
					vis[e.to]=true;
					val[e.to]=e.wt-val[v];
					Q.emplace(e.to);
				}
				else{
					if(val[v]+val[e.to]!=e.wt) return puts("No"),0;
				}
			}
		}

		if(row_min+col_min<0) return puts("No"),0;
	}
	puts("Yes");

	return 0;
}
