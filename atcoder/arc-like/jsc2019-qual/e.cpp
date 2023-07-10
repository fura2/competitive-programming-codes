#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class union_find{
	int n;
	vector<int> p,wt;
public:
	union_find(int n=0){ build(n); }
	void build(int n){
		this->n=n;
		p.assign(n,-1);
		wt.assign(n,0);
	}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
			wt[u]+=wt[v];
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
	int& weight(int u){ return wt[find(u)]; }
};

int main(){
	int n,h,w; scanf("%d%d%d",&n,&h,&w);
	vector<tuple<int,int,int>> E(n);
	rep(i,n){
		int r,c,a; scanf("%d%d%d",&r,&c,&a); r--; c--;
		E[i]={a,r,h+c};
	}

	sort(E.rbegin(),E.rend());

	lint ans=0;
	union_find U(h+w);
	for(auto [a,u,v]:E){
		if(U.weight(u)+U.weight(v)<U.size(u)+U.size(v)){
			U.unite(u,v);
			U.weight(u)+=1;
			ans+=a;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
