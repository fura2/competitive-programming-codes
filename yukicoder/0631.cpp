#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
class starry_sky_tree{
	int sz;
	vector<T> seg;

	void maintain(int u){
		if(1<=u && u<sz){
			T mx=std::max(seg[2*u],seg[2*u+1]);
			seg[u]+=mx;
			seg[2*u  ]-=mx;
			seg[2*u+1]-=mx;
		}
	}
	T max(int l,int r,int a,int b,int u,T cum)const{
		if(b<=l || r<=a) return numeric_limits<T>::min();
		if(l<=a && b<=r) return cum+seg[u];
		T lmax=max(l,r,a,(a+b)/2,2*u  ,cum+seg[u]);
		T rmax=max(l,r,(a+b)/2,b,2*u+1,cum+seg[u]);
		return std::max(lmax,rmax);
	}
public:
	starry_sky_tree(int n){
		for(sz=1;sz<n;sz<<=1);
		seg.assign(2*sz,T());
	}
	void add(int l,int r,const T& val){
		int a,b;
		for(a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1){ seg[a]+=val; a++; }
			if(b&1){ b--; seg[b]+=val; }
			maintain((a-1)>>1);
			maintain(b>>1);
		}
		for(int u=a-1;u>=1;u>>=1) maintain(u);
		for(int u= b ;u>=1;u>>=1) maintain(u);
	}
	T max(int l,int r)const{ return max(l,r,0,sz,1,0); }
};

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n-1);
	rep(i,n-1) scanf("%lld",&a[i]);

	starry_sky_tree<lint> SS(n-1);
	rep(i,n-1) SS.add(i,i+1,a[i]+3*(n-i-1));

	int q; scanf("%d",&q);
	rep(_,q){
		int l,r;
		lint d; scanf("%d%d%lld",&l,&r,&d); l--;
		SS.add(l,r,d);
		printf("%lld\n",SS.max(0,n-1));
	}

	return 0;
}
