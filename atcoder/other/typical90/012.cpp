#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n=0){ build(n); }
	void build(int n){
		this->n=n;
		p.assign(n,-1);
	}
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

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w,q; scanf("%d%d%d",&h,&w,&q);

	union_find U(h*w);
	vector B(h,string(w,'.'));
	rep(_,q){
		int type; scanf("%d",&type);
		if(type==1){
			int r,c; scanf("%d%d",&r,&c); r--; c--;
			B[r][c]='#';
			rep(k,4){
				int x=r+dx[k],y=c+dy[k];
				if(0<=x && x<h && 0<=y && y<w && B[x][y]=='#'){
					U.unite(r*w+c,x*w+y);
				}
			}
		}
		else{
			int r1,c1,r2,c2; scanf("%d%d%d%d",&r1,&c1,&r2,&c2); r1--; c1--; r2--; c2--;
			puts(B[r1][c1]=='#'&&U.is_same(r1*w+c1,r2*w+c2)?"Yes":"No");
		}
	}

	return 0;
}
