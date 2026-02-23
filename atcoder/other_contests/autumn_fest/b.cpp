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
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	union_find U(h*w);
	rep(i,h) rep(j,w) {
		if(i+2<h && B[i][j]==B[i+1][j] && B[i+2][j]==B[i][j]){
			U.unite(i*w+j,(i+1)*w+j);
			U.unite(i*w+j,(i+2)*w+j);
		}
		if(j+2<w && B[i][j]==B[i][j+1] && B[i][j]==B[i][j+2]){
			U.unite(i*w+j,i*w+(j+1));
			U.unite(i*w+j,i*w+(j+2));
		}
	}

	rep(i,h) rep(j,w) {
		if(i+1<h && B[i][j]==B[i+1][j] && U.size(i*w+j)>1 && U.size((i+1)*w+j)>1){
			U.unite(i*w+j,(i+1)*w+j);
		}
		if(j+1<w && B[i][j]==B[i][j+1] && U.size(i*w+j)>1 && U.size(i*w+(j+1))>1){
			U.unite(i*w+j,i*w+(j+1));
		}
	}

	set<int> Ans;
	rep(i,h) rep(j,w) if(U.size(i*w+j)>1) Ans.emplace(U.find(i*w+j));
	cout<<Ans.size()<<'\n';

	return 0;
}
