#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
class max_monoid{
	T a;
public:
	max_monoid():a(numeric_limits<T>::min()){}
	max_monoid(const T& val):a(val){}
	max_monoid operator*(const max_monoid& x)const{
		return max(a,x.a);
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

template<class T>
class min_monoid{
	T a;
public:
	min_monoid():a(numeric_limits<T>::max()){}
	min_monoid(const T& val):a(val){}
	min_monoid operator*(const min_monoid& x)const{
		return min(a,x.a);
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> l(n-1),r(n-1);
	rep(i,n-1) scanf("%d%d",&l[i],&r[i]);

	segment_tree<max_monoid<int>> L(l);
	segment_tree<min_monoid<int>> U(r);

	rep(_,q){
		int t,u; scanf("%d%d",&t,&u); u--;

		int lo1=-1,hi1=u;
		while(hi1-lo1>1){
			int mi=(lo1+hi1)/2;
			if(L.product(mi,u).get()<=t && t<=U.product(mi,u).get()) hi1=mi;
			else lo1=mi;
		}

		int lo2=u+1,hi2=n+1;
		while(hi2-lo2>1){
			int mi=(lo2+hi2)/2;
			if(L.product(u,mi-1).get()<=t && t<=U.product(u,mi-1).get()) lo2=mi;
			else hi2=mi;
		}

		printf("%d\n",lo2-hi1);
	}

	return 0;
}
