#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class M>
class segment_tree{
	int n,sz;
	vector<M> seg;
public:
	segment_tree(){}
	segment_tree(int n){ build(n); }
	template<class T>
	segment_tree(const vector<T>& a){ build(a); }
	void build(int n){
		this->n=n;
		for(sz=1;sz<n;sz<<=1);
		seg.assign(2*sz,M());
	}
	template<class T>
	void build(const vector<T>& a){
		build(a.size());
		rep(i,a.size()) seg[sz+i]=a[i];
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
	template<class F>
	int max_right(int l,const F& f)const{
		if(l==n) return n;
		M cum;
		auto dfs=[&](auto&& dfs,int a,int b,int u){
			if(a==b-1){
				cum=cum*seg[u];
				return f(cum)?b:a;
			}

			int c=(a+b)/2;
			if(c<=l){
				return dfs(dfs,c,b,2*u+1);
			}
			if(l<=a && f(cum*seg[u])){
				cum=cum*seg[u];
				return b;
			}

			int idx=dfs(dfs,a,c,2*u);
			if(idx<c) return idx;
			return dfs(dfs,c,b,2*u+1);
		};
		return min(dfs(dfs,0,sz,1),n);
	}
	template<class F>
	int min_left(int r,const F& f)const{
		if(r==0) return 0;
		M cum;
		auto dfs=[&](auto&& dfs,int a,int b,int u){
			if(a==b-1){
				cum=seg[u]*cum;
				return f(cum)?a:b;
			}

			int c=(a+b)/2;
			if(r<=c){
				return dfs(dfs,a,c,2*u);
			}
			if(b<=r && f(seg[u]*cum)){
				cum=seg[u]*cum;
				return a;
			}

			int idx=dfs(dfs,c,b,2*u+1);
			if(idx>c) return idx;
			return dfs(dfs,a,c,2*u);
		};
		return dfs(dfs,0,sz,1);
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

		int idx1=max(L.min_left(u,[&](const auto& x){ return x.get()<=t; }),
					 U.min_left(u,[&](const auto& x){ return x.get()>=t; }));
		int idx2=min(L.max_right(u,[&](const auto& x){ return x.get()<=t; }),
					 U.max_right(u,[&](const auto& x){ return x.get()>=t; }));
		printf("%d\n",idx2-idx1+1);
	}

	return 0;
}
