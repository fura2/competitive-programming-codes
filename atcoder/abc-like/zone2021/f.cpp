#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using ulint=unsigned long long;

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

auto basis(const vector<unsigned long long>& a){
	vector<unsigned long long> B;
	for(auto v:a){
		for(const auto& b:B) v=min(v,v^b);
		if(v!=0) B.emplace_back(v);
	}
	return B;
}

bool is_linearly_independent(unsigned long long v,const vector<unsigned long long>& B){
	for(const auto& b:B) v=min(v,v^b);
	return v!=0;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	n=log2(n);

	vector<bool> ng(1<<n);
	rep(i,m){
		int a; scanf("%d",&a);
		ng[a]=true;
	}

	vector<ulint> V,B;
	rep(i,1<<n) if(!ng[i]) {
		if(is_linearly_independent(i,B)){
			V.emplace_back(i);
			B=basis(V);
		}
	}

	if(V.size()!=n){
		puts("-1");
		return 0;
	}

	union_find U(1<<n);
	rep(S,1<<n) rep(i,n) {
		int T=S^V[i];
		if(!U.is_same(S,T)){
			U.unite(S,T);
			printf("%d %d\n",S,T);
		}
	}

	return 0;
}
