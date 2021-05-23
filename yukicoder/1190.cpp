#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
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

const int INF=1<<29;

int main(){
	int n,m,p,s,t;
	scanf("%d%d%d%d%d",&n,&m,&p,&s,&t); s--; t--;
	graph G(2*n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(G,u,v+n);
		add_undirected_edge(G,u+n,v);
	}

	auto ds=distance(G,s);
	auto dt=distance(G,t);

	vector<int> ans;
	rep(u,n){
		bool ok=false;
		if(p%2==0){
			if(ds[ u ]<INF && dt[ u ]<INF && ds[ u ]+dt[ u ]<=p) ok=true;
			if(ds[u+n]<INF && dt[u+n]<INF && ds[u+n]+dt[u+n]<=p) ok=true;
		}
		else{
			if(ds[ u ]<INF && dt[u+n]<INF && ds[ u ]+dt[u+n]<=p) ok=true;
			if(ds[u+n]<INF && dt[ u ]<INF && ds[u+n]+dt[ u ]<=p) ok=true;
		}
		if(ok) ans.emplace_back(u);
	}

	if(ans.empty()){
		puts("-1");
	}
	else{
		printf("%ld\n",ans.size());
		for(int u:ans) printf("%d\n",u+1);
	}

	return 0;
}
