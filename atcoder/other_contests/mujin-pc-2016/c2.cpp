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
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> E(m);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		E[i]={u,v};
	}

	int ans=0;
	rep(S,1<<(n-1)){
		union_find U(n);
		rep(i,m){
			int u,v; tie(u,v)=E[i];
			if((S>>u&1)!=(S>>v&1)) U.unite(u,v);
		}
		if(U.size()==1) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
