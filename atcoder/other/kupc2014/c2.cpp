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
	int n,m,k; scanf("%d%d%d",&n,&m,&k);

	union_find U(n+m);
	rep(i,k){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		U.unite(u,n+v);
	}

	int ans=0;
	rep(i,n*m){
		if(!U.is_same(i%n,n+i%m)) ans=i+1;
		U.unite(i%n,n+i%m);
	}
	printf("%d\n",ans);

	return 0;
}
