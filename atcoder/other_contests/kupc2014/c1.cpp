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
	vector<pair<int,int>> p(k);
	rep(i,k){
		scanf("%d%d",&p[i].first,&p[i].second);
		p[i].first--;
		p[i].second--;
	}

	int lo=-1,hi=n*m;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		union_find U(n+m);
		for(auto [u,v]:p){
			U.unite(u,n+v);
		}
		rep(i,mi){
			U.unite(i%n,n+i%m);
		}

		bool ok=false;
		rep(i,n*m) if(!U.is_same(i%n,n+i%m)) ok=true;
		(ok?lo:hi)=mi;
	}
	printf("%d\n",hi);

	return 0;
}
