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
	union_find U(n);
	vector<int> deg(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		U.unite(u,v);
		deg[u]++;
		deg[v]++;
	}

	int cnt=0;
	vector<bool> vis(n);
	rep(u,n){
		int r=U.find(u);
		if(!vis[r] && U.size(r)>=2){
			vis[r]=true;
			cnt++;
		}
	}

	int odd=0;
	rep(u,n) if(deg[u]%2==1) odd++;

	puts(cnt==1&&odd<=2?"YES":"NO");

	return 0;
}
