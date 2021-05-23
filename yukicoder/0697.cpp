#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	static int B[3000][3000];
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	union_find U(h*w);
	rep(i,h) rep(j,w) if(B[i][j]==1) {
		if(j<w-1 && B[i][j+1]==1) U.unite(i*w+j,i*w+(j+1));
		if(i<h-1 && B[i+1][j]==1) U.unite(i*w+j,(i+1)*w+j);
	}

	int ans=U.size();
	rep(i,h) rep(j,w) if(B[i][j]==0) ans--;
	printf("%d\n",ans);

	return 0;
}
