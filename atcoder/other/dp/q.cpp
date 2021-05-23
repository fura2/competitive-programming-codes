#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
class segment_tree{
	int n;
	vector<T> dat;
	T query(int l,int r,int a,int b,int u){
		if(l<=a && b<=r) return dat[u];
		T res=0;
		int c=(a+b)/2;
		if(l<c && a<r) res=max(res,query(l,r,a,c,2*u+1));
		if(l<b && c<r) res=max(res,query(l,r,c,b,2*u+2));
		return res;
	}
public:
	segment_tree(int N){
		for(n=1;n<N;n*=2);
		dat.assign(2*n-1,0);
	}
	void update(int u,T v){
		u+=n-1;
		dat[u]=max(dat[u],v);
		while(u>0) u=(u-1)/2, dat[u]=max(dat[2*u+1],dat[2*u+2]);
	}
	T query(int l,int r){ return query(l,r,0,n,0); }
};

int main(){
	int n; scanf("%d",&n);
	vector<int> h(n),a(n);
	rep(i,n) scanf("%d",&h[i]);
	rep(i,n) scanf("%d",&a[i]);

	vector<pair<int,int>> p(n);
	rep(i,n) p[i]={h[i],i};
	sort(p.begin(),p.end());

	segment_tree<lint> ST(n);
	for(auto q:p){
		int i=q.second;
		ST.update(i,ST.query(0,i)+a[i]);
	}
	printf("%lld\n",ST.query(0,n));

	return 0;
}
