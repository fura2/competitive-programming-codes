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
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	union_find U(n);
	rep(i,n) rep(j,i) if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=100) U.unite(i,j);

	double ans=1;
	rep(i,n) rep(j,i+1) if(U.is_same(i,j)) ans=max(ans,hypot(x[i]-x[j],y[i]-y[j])+2);
	printf("%.9f\n",ans);

	return 0;
}
