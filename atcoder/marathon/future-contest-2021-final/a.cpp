#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
	vector<vector<int>> C;
public:
	union_find(int n):n(n),p(n,-1),C(n){
		rep(u,n) C[u].emplace_back(u);
	}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
			C[u].insert(C[u].end(),C[v].begin(),C[v].end());
			C[v].clear();
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
	vector<int> connected_component(int u){ return C[find(u)]; }
};

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int h=50,w=50,c;
int val[50][50];

int score(vector<pair<int,int>> path){
	int res=0;
	bool vis[50][50]={};
	for(auto [x,y]:path){
		vis[x][y]=true;
		int cnt=0;
		rep(k,4){
			int x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && !vis[x2][y2]);
			else cnt++;
		}
		res+=val[x][y]-c/cnt;
	}
	return res;
}

int main(){
	scanf("%d",&c);
	rep(i,h) rep(j,w) scanf("%d",&val[i][j]);

	int val_max=0,val_min=1e9;
	rep(i,h) rep(j,w) {
		val_max=max(val_max,val[i][j]);
		val_min=min(val_min,val[i][j]);
	}

	const int N=20;
	vector<pair<int,int>> ans;
	rep(d,N+1){
		int th=(val_min*(N-d)+val_max*d)/N;

		bool used[50][50]={};
		rep(i,h) rep(j,w) if(val[i][j]>=th) used[i][j]=true;

		union_find U(h*w+1);
		rep(i,h) rep(j,w) {
			if(used[i][j]){
				rep(k,4){
					int x=i+dx[k],y=j+dy[k];
					if(0<=x && x<h && 0<=y && y<w && used[x][y]){
						U.unite(i*w+j,x*w+y);
					}
				}
			}
			if(i==0 || i==h-1 || j==0 || j==w-1) U.unite(i*w+j,h*w);
		}

		rep(i,h) rep(j,w) if(used[i][j] && U.find(i*w+j)!=U.find(h*w)) {
			int gx=-1,gy=-1;
			pair<int,int> pre[50][50];

			queue<pair<int,int>> Q;
			bool vis[50][50]={};
			for(int u:U.connected_component(U.find(i*w+j))){
				int x=u/w,y=u%w;
				Q.emplace(x,y);
				vis[x][y]=true;
			}
			while(!Q.empty()){
				int x,y; tie(x,y)=Q.front(); Q.pop();
				if(U.find(x*w+y)==U.find(h*w)){
					gx=x;
					gy=y;
					break;
				}
				rep(k,4){
					int x2=x+dx[k],y2=y+dy[k];
					if(0<x2 && x2<h && 0<=y2 && y2<w && !vis[x2][y2]){
						Q.emplace(x2,y2);
						vis[x2][y2]=true;
						pre[x2][y2]={x,y};
					}
				}
			}

			int x=gx,y=gy;
			while(1){
				int x2,y2; tie(x2,y2)=pre[x][y];
				used[x][y]=true;
				U.unite(x*w+y,x2*w+y2);
				if(U.find(i*w+j)==U.find(h*w)) break;
				x=x2; y=y2;
			}
		}

		vector<pair<int,int>> path;
		queue<pair<int,int>> Q;
		bool vis[50][50]={};
		rep(i,h) rep(j,w) if(i==0 || i==h-1 || j==0 || j==w-1) {
			if(used[i][j]){
				Q.emplace(i,j);
				vis[i][j]=true;
			}
		}
		while(!Q.empty()){
			int x,y; tie(x,y)=Q.front(); Q.pop();
			path.emplace_back(x,y);
			rep(k,4){
				int x2=x+dx[k],y2=y+dy[k];
				if(0<x2 && x2<h && 0<=y2 && y2<w && used[x2][y2] && !vis[x2][y2]){
					Q.emplace(x2,y2);
					vis[x2][y2]=true;
				}
			}
		}
/*
printf("d = %d, th = %d\n",d,th);
bool V[50][50]={}; for(auto [x,y]:path) V[x][y]=true;
rep(i,h){ rep(j,w) printf("%c",V[i][j]?'*':'.'); puts(""); } puts("--");
printf("  score = %d\n",score(path));
*/
		if(score(ans)<score(path)) ans=path;
	}

	printf("%ld\n",ans.size());
	for(auto [x,y]:ans) printf("%d %d\n",x,y);

	return 0;
}
