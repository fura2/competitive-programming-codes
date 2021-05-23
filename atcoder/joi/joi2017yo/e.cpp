#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	vector<int> X;
	rep(i,h) rep(j,w) X.emplace_back(B[i][j]);
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	rep(i,h) rep(j,w) B[i][j]=lower_bound(X.begin(),X.end(),B[i][j])-X.begin();

	int n=h*w;
	graph D(n);
	vector bottom(n,true);
	rep(i,h) rep(j,w) {
		rep(k,4){
			int x=i+dx[k],y=j+dy[k];
			if(0<=x && x<h && 0<=y && y<w && B[i][j]<B[x][y]){
				add_directed_edge(D,i*w+j,x*w+y);
				bottom[x*w+y]=false;
			}
		}
	}

	vector<int> vis(n,-1); // -1 : 未訪問, -2 : 二箇所以上から訪問済み
	rep(u,n) if(bottom[u]) {
		vis[u]=u;
		queue<int> Q; Q.emplace(u);

		while(!Q.empty()){
			int v=Q.front(); Q.pop();
			for(int w:D[v]){
				if(vis[w]==-1){
					vis[w]=u;
					Q.emplace(w);
				}
				else if(vis[w]!=u && vis[w]!=-2){
					vis[w]=-2;
				}
			}
		}
	}

	queue<int> Q;
	rep(u,n){
		if(vis[u]==-2){
			Q.emplace(u);
			vis[u]=1;
		}
		else vis[u]=0;
	}
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:D[u]){
			if(vis[v]==0){
				vis[v]=1;
				Q.emplace(v);
			}
		}
	}

	printf("%lu\n",count(vis.begin(),vis.end(),true));

	return 0;
}
