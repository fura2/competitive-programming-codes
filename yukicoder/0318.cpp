#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

class segment_tree_dual{
	int n;
	vector<int> seg;

	void chmax(int l,int r,int a,int b,int u,int x){
		if(l<=a && b<=r){ seg[u]=max(seg[u],x); return; }
		int c=(a+b+1)/2;
		if(l<c && a<r) chmax(l,r,a,c,2*u  ,x);
		if(l<b && c<r) chmax(l,r,c,b,2*u+1,x);
	}

public:
	segment_tree_dual(int N){
		for(n=1;n<N;n*=2);
		seg.assign(2*n,-INF);
	}

	void chmax(int l,int r,int x){ chmax(l,r,0,n,1,x); }

	int get(int u){
		u+=n;
		int res=seg[u];
		for(u/=2;u>=1;u/=2) res=max(res,seg[u]);
		return res;
	}
};

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	map<int,vector<int>> f;
	rep(i,n) f[a[i]].emplace_back(i);

	segment_tree_dual ST(n);
	for(auto [x,v]:f){
		int l=INF,r=-INF;
		for(auto i:v){
			l=min(l,i);
			r=max(r,i+1);
		}
		ST.chmax(l,r,x);
	}
	rep(i,n) printf("%d%c",ST.get(i),i<n-1?' ':'\n');

	return 0;
}
