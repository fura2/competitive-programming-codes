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
	int w,h; scanf("%d%d",&w,&h);
	int B[100][100];
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	union_find U(h*w);
	rep(i,h) rep(j,w) rep(k,4) if(k==0 || k==3) {
		int y=i+dy[k],x=j+dx[k];
		if(0<=y && y<h && 0<=x && x<w && B[i][j]==B[y][x]){
			if(U.is_same(i*w+j,y*w+x)) return puts("possible"),0;
			U.unite(i*w+j,y*w+x);
		}
	}
	puts("impossible");

	return 0;
}
