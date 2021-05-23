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
	int n,m; scanf("%d%d",&n,&m);

	lint sum=0;
	vector<tuple<int,int,lint>> I;
	rep(i,n){
		lint a; scanf("%lld",&a);
		sum+=a;
		I.emplace_back(i,i+1,a);
	}
	rep(i,m){
		int l,r;
		lint w; scanf("%d%d%lld",&l,&r,&w); l--;
		I.emplace_back(l,r,w);
	}

	sort(I.begin(),I.end(),[&](auto x,auto y){ // 右端の昇順にソート
		return get<1>(x)<get<1>(y);
	});

	segment_tree<min_monoid<lint>> S(n+1);
	S.update(0,0LL);
	for(auto [l,r,w]:I){
		lint tmp=S.product(l,r).get();
		if(S[r].get()>tmp+w){
			S.update(r,tmp+w);
		}
	}
	printf("%lld\n",sum-S[n].get());

	return 0;
}
