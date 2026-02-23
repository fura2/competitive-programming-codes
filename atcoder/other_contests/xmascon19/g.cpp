#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	char B[300][301];
	rep(i,h) scanf("%s",B[i]);

	bipartite_graph G(29,29);
	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		int y1=i,x1=j;
		if(y1%2==1) y1+=5, x1-=2;
		x1-=5*y1/2; y1=0;
		x1%=29; if(x1<0) x1+=29;

		int y2=i,x2=j;
		if(y2%2==1) y2+=5, x2+=2;
		x2+=5*y2/2; y2=0;
		x2%=29; if(x2<0) x2+=29;

		G.add_edge(x1,x2);
	}
	printf("%d\n",G.bipartite_matching().first);

	return 0;
}
