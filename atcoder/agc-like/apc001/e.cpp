#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	vector<int> deg(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v);
		add_undirected_edge(T,u,v);
		deg[u]++;
		deg[v]++;
	}

	vector<int> freq(n);
	rep(u,n) freq[deg[u]]++;

	if(freq[1]==2 && freq[2]==n-2){ // path graph
		puts("1");
		return 0;
	}

	vector<bool> b(n);
	rep(u,n) if(deg[u]==1) {
		int v=u,w=T[u][0];
		while(deg[w]==2){
			for(int x:T[w]) if(x!=v) {
				v=w;
				w=x;
				break;
			}
		}
		b[w]=true;
	}
	printf("%ld\n",freq[1]-count(b.begin(),b.end(),true));

	return 0;
}
