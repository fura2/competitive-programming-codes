#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

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

int main(){
	int h,w; scanf("%d%d",&h,&w);
	static char B[1500][1501];
	rep(i,h) scanf("%s",B[i]);

	static int dp[1500][1500]; // dp[i][j] := ( (i, j) を左上のマスとする最大の正方形の一辺の長さ )
	rep(i,h) if(B[i][w-1]=='.') dp[i][w-1]=1;
	rep(j,w) if(B[h-1][j]=='.') dp[h-1][j]=1;
	for(int i=h-2;i>=0;i--) for(int j=w-2;j>=0;j--) if(B[i][j]=='.') {
		dp[i][j]=min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]})+1;
	}

	vector<pair<int,int>> Ev1[1501];
	rep(i,h) rep(j,w) if(B[i][j]=='.') Ev1[dp[i][j]].emplace_back(i,j);

	vector<tuple<int,int,int>> Ev2[1501];
	int q; scanf("%d",&q);
	rep(i,q){
		int x,y,l; scanf("%d%d%d",&y,&x,&l); x--; y--;
		Ev2[l].emplace_back(i,y,x);
	}

	vector<int> ans(q);
	union_find U(h*w);
	static bool ok[1500][1500];
	for(int sz=1500;sz>0;sz--){
		for(auto e:Ev1[sz]){
			int x,y; tie(y,x)=e;
			ok[y][x]=true;
			rep(k,4){
				int xx=x+dx[k],yy=y+dy[k];
				if(0<=xx && xx<w && 0<=yy && yy<h && ok[yy][xx]){
					U.unite(y*w+x,yy*w+xx);
				}
			}
		}
		for(auto e:Ev2[sz]){
			int id,x,y; tie(id,y,x)=e;
			ans[id]=U.size(y*w+x);
		}
	}

	rep(i,q) printf("%d\n",ans[i]);

	return 0;
}
