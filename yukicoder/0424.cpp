#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_edge(graph& G,int u,int v){
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

int main(){
	int h,w; scanf("%d%d",&h,&w);
	int sx,sy,gx,gy; scanf("%d%d%d%d",&sy,&sx,&gy,&gx); sx--; sy--; gx--; gy--;
	char B[50][51];
	rep(i,h) scanf("%s",B[i]);

	graph G(h*w);
	rep(i,h) rep(j,w) {
		if(i<h-1 && abs(B[i][j]-B[i+1][j])<=1) add_edge(G,i*w+j,(i+1)*w+j);
		if(j<w-1 && abs(B[i][j]-B[i][j+1])<=1) add_edge(G,i*w+j,i*w+(j+1));
		if(i<h-2 && B[i][j]==B[i+2][j] && B[i][j]>B[i+1][j]) add_edge(G,i*w+j,(i+2)*w+j);
		if(j<w-2 && B[i][j]==B[i][j+2] && B[i][j]>B[i][j+1]) add_edge(G,i*w+j,i*w+(j+2));
	}
	puts(distance(G,sy*w+sx)[gy*w+gx]<INT_MAX?"YES":"NO");

	return 0;
}
