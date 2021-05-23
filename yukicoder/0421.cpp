#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

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

int main(){
	int h,w; scanf("%d%d",&h,&w);
	char B[50][51];
	rep(i,h) scanf("%s",B[i]);

	bipartite_graph G(h*w,h*w);
	int nb=0,nw=0;
	rep(i,h) rep(j,w) if(B[i][j]!='.') {
		if(B[i][j]=='b') nb++;
		if(B[i][j]=='w') nw++;
		if((i+j)%2==0) rep(k,4) {
			int y=i+dy[k],x=j+dx[k];
			if(0<=y && y<h && 0<=x && x<w && B[y][x]!='.' && B[i][j]!=B[y][x]){
				G.add_edge(i*w+j,y*w+x);
			}
		}
	}

	int k=G.bipartite_matching().first;
	printf("%d\n",100*k+10*min(nb-k,nw-k)+(nb-k+nw-k-2*min(nb-k,nw-k)));

	return 0;
}
