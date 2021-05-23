#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

bool is_DAG(const graph& G){
	int n=G.size();
	vector<int> deg(n);
	rep(u,n) for(int v:G[u]) deg[v]++;

	int cnt=0;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		cnt++;
		for(int v:G[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return cnt==n;
}

vector<int> topological_order(const graph& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(int v:D[u]) deg[v]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(int v:D[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return res;
}

int main(){
	int n; cin>>n;
	vector<string> s(n);
	rep(i,n) cin>>s[i];
	int m; cin>>m;
	s.resize(n+m);
	rep(i,m) cin>>s[n+i];

	map<char,int> f;
	rep(i,n+m){
		for(char c:s[i]) if(f.count(c)==0) {
			int idx=f.size();
			f[c]=idx;
		}
	}
	int k=f.size();

	graph G(k);
	union_find U(k);
	rep(i,n+m){
		rep(j,s[i].length()-1){
			add_directed_edge(G,f[s[i][j]],f[s[i][j+1]]);
			U.unite(f[s[i][j]],f[s[i][j+1]]);
		}
	}

	string g(k,'?');
	for(auto p:f) g[p.second]=p.first;

	if(is_DAG(G) && U.size()==1){
		for(int i:topological_order(G)) putchar(g[i]);
		puts("");
	}
	else puts("-1");

	return 0;
}
