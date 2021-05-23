#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
	vector<lint> x(n),y(n);
	rep(i,n) scanf("%lld%lld",&x[i],&y[i]);

	vector<tuple<lint,int,int>> E;
	rep(i,n) rep(j,i) {
		E.emplace_back((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),i,j);
	}
	sort(E.begin(),E.end());

	union_find U(n);
	for(const auto& e:E){
		U.unite(get<1>(e),get<2>(e));
		if(U.is_same(0,n-1)){
			lint ans=lint(sqrt(get<0>(e))-0.1)/10*10;
			while(ans*ans<get<0>(e)) ans+=10;
			printf("%lld\n",ans);
			break;
		}
	}
	return 0;
}
