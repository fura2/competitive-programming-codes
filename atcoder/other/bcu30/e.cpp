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
	int n,k,q; cin>>n>>k>>q;
	vector<string> B(n);
	rep(i,n) cin>>B[i];

	vector cum(n+1,vector(n+1,0));
	rep(i,n) rep(j,n) cum[i+1][j+1]=cum[i+1][j]+cum[i][j+1]-cum[i][j]+(B[i][j]=='#'?1:0);

	int m=n-k+1;
	vector ok(m,vector(m,false));
	rep(i,m) rep(j,m) ok[i][j]=(cum[i+k][j+k]-cum[i+k][j]-cum[i][j+k]+cum[i][j]==0);

	union_find U(m*m);
	rep(i,m) rep(j,m) if(ok[i][j]) {
		if(i<m-1 && ok[i+1][j]) U.unite(i*m+j,(i+1)*m+j);
		if(j<m-1 && ok[i][j+1]) U.unite(i*m+j,i*m+(j+1));
	}

	rep(_,q){
		int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2; x1--; y1--; x2--; y2--;
		puts(U.is_same(x1*m+y1,x2*m+y2)?"Yes":"No");
	}

	return 0;
}
