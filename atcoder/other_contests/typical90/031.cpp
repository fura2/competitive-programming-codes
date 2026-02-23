#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

vector<int> topological_sort(const graph& D){
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

vector<int> Grundy(const graph& D){
	auto ord=topological_sort(D);

	int n=D.size(),m=0;
	rep(u,n) m=max(m,int(D[u].size()));

	vector<int> g(n),last(m+1,-1);
	rep(i,n){
		int u=ord[n-i-1];
		for(int v:D[u]) last[g[v]]=u;
		while(last[g[u]]==u) g[u]++;
	}
	return g;
}

const int N=1500;
graph D(51*N);

int main(){
	rep(i,51) rep(j,N) {
		if(i>=1){
			add_directed_edge(D,i*N+j,(i-1)*N+j+i);
		}
		for(int k=1;k<=j/2;k++){
			add_directed_edge(D,i*N+j,i*N+j-k);
		}
	}
	auto g=Grundy(D);

	int n; scanf("%d",&n);
	vector<int> w(n),b(n);
	rep(i,n) scanf("%d",&w[i]);
	rep(i,n) scanf("%d",&b[i]);

	int ans=0;
	rep(i,n) ans^=g[w[i]*N+b[i]];
	puts(ans>0?"First":"Second");

	return 0;
}
