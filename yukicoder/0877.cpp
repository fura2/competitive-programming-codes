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
	M get(int l,int r)const{
		M lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*seg[a++];
			if(b&1) rcum=seg[--b]*rcum;
		}
		return lcum*rcum;
	}
	template<class N,class F>
	N query(int l,int r,const F& f){
		N lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*f(seg[a++]);
			if(b&1) rcum=f(seg[--b])*rcum;
		}
		return lcum*rcum;
	}
};

template<class T>
class sequence_sum_monoid{
	vector<T> a,cum;
public:
	sequence_sum_monoid():cum(1){}
	sequence_sum_monoid(const T& val):a(1,val),cum{0,val}{}
	sequence_sum_monoid(const vector<T>& x):a(x),cum(x.size()+1){
		sort(a.begin(),a.end());
		rep(i,x.size()) cum[i+1]=cum[i]+a[i];
	}
	sequence_sum_monoid operator*(const sequence_sum_monoid& x)const{
		vector<T> res;
		merge(a.begin(),a.end(),x.a.begin(),x.a.end(),back_inserter(res));
		return res;
	}
	lint f(lint t){
		int idx=upper_bound(a.begin(),a.end(),t)-a.begin();
		return cum.back()-cum[idx]-(a.size()-idx)*t;
	}
};

template<class T>
class add_monoid{
	T a;
public:
	add_monoid():a(){}
	add_monoid(const T& val):a(val){}
	add_monoid operator*(const add_monoid& x)const{
		return a+x.a;
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	segment_tree<sequence_sum_monoid<lint>> S(a);
	rep(_,q){
		int l,r,t; scanf("%*d%d%d%d",&l,&r,&t); l--;
		auto ans=S.query<add_monoid<lint>>(l,r,[&](sequence_sum_monoid<lint>& x)->add_monoid<lint>{
			return x.f(t);
		});
		printf("%lld\n",ans.get());
	}

	return 0;
}
