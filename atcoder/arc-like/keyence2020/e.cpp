#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> val(n);
	rep(u,n) scanf("%d",&val[u]);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
	}

	vector<pair<int,int>> p(n);
	rep(u,n) p[u]={val[u],u};
	sort(p.begin(),p.end());

	vector<int> color(n,-1),wt(m,1e9);
	rep(i,n){
		int u=p[i].second;
		if(color[u]!=-1) continue;

		int v=-1,id;
		for(auto e:G[u]) if(val[e.to]<=val[u]) { v=e.to; id=e.wt; break; }
		if(v==-1) return puts("-1"),0;

		if(color[v]==-1){
			color[u]=0;
			color[v]=1;
		}
		else{
			color[u]=1-color[v];
		}
		wt[id]=val[u];
	}

	rep(u,n) putchar(color[u]==0?'B':'W'); puts("");
	rep(i,m) printf("%d\n",wt[i]);

	return 0;
}
