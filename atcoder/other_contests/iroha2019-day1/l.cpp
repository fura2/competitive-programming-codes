#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class M>
class segment_tree{
	int sz;
	vector<M> seg;
public:
	segment_tree(){}
	segment_tree(int n){ build(n); }
	template<class T>
	segment_tree(const vector<T>& a){ build(a); }
	void build(int n){
		for(sz=1;sz<n;sz<<=1);
		seg.assign(2*sz,M());
	}
	template<class T>
	void build(const vector<T>& a){
		int n=a.size();
		build(n);
		rep(i,n) seg[sz+i]=a[i];
		for(int i=sz-1;i>0;i--){
			seg[i]=seg[2*i]*seg[2*i+1];
		}
	}
	const M& operator[](int i)const{
		return seg[sz+i];
	}
	void update(int i,const M& x){
		i+=sz;
		seg[i]=x;
		for(i>>=1;i>0;i>>=1) seg[i]=seg[2*i]*seg[2*i+1];
	}
	M product(int l,int r)const{
		M lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*seg[a++];
			if(b&1) rcum=seg[--b]*rcum;
		}
		return lcum*rcum;
	}
	template<class N,class F>
	N operate(int l,int r,const F& f){
		N lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*f(seg[a++]);
			if(b&1) rcum=f(seg[--b])*rcum;
		}
		return lcum*rcum;
	}
};

template<class T>
class or_monoid{
	T a;
public:
	or_monoid():a(){}
	or_monoid(const T& val):a(val){}
	or_monoid operator*(const or_monoid& x)const{
		return a|x.a;
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	segment_tree<or_monoid<lint>> S(a);

	lint lo=0,hi=1LL<<60;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		lint cnt=0; // 要素の or が mi 以上になる区間の個数
		int r=0;
		rep(l,n){
			if(S.product(l,n).get()<mi) continue;

			r=max(r,l+1);
			lint x=S.product(l,r).get();
			while(r<n && x<mi){
				x|=a[r];
				r++;
			}
			cnt+=n-r+1;
		}

		if(cnt<k) hi=mi;
		else      lo=mi;
	}
	printf("%lld\n",lo);

	return 0;
}
