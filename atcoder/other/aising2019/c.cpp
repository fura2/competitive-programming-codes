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
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	union_find U(h*w);
	rep(i,h) rep(j,w) {
		if(i<h-1 && B[i][j]!=B[i+1][j]) U.unite(i*w+j,(i+1)*w+j);
		if(j<w-1 && B[i][j]!=B[i][j+1]) U.unite(i*w+j,i*w+(j+1));
	}

	map<int,lint> fb,fw;
	rep(i,h) rep(j,w) {
		if(B[i][j]=='#') ++fb[U.find(i*w+j)];
		if(B[i][j]=='.') ++fw[U.find(i*w+j)];
	}

	lint ans=0;
	for(auto p:fb) ans+=fb[p.first]*fw[p.first];
	cout<<ans<<'\n';

	return 0;
}
