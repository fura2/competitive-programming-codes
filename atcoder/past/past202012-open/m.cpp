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
	lint L; scanf("%d%lld",&n,&L);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	auto check=[&](lint T){
		segment_tree<or_monoid<int>> S(n+1); // S[i] = (a[0..i) を T 以上 L 以下のパーツに分割できるか)
		S.update(0,1);
		int l=0,r=0;
		rep(i,n){
			while(cum[i+1]-cum[l]> L) l++;
			while(cum[i+1]-cum[r]>=T) r++;
			if(S.product(l,r).get()==1) S.update(i+1,1);
		}
		return S.product(n,n+1).get()==1;
	};

	lint lo=0,hi=L+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		if(check(mi)) lo=mi;
		else          hi=mi;
	}
	printf("%lld\n",lo);

	return 0;
}
