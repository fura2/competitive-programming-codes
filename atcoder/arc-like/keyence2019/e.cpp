#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
using lint=long long;

using namespace std;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n=0){ build(n); }
	void build(int n){
		this->n=n;
		p.assign(n,-1);
	}
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

template<class T>
T Kruskal(int n,vector<tuple<int,int,T>> E){
	sort(E.begin(),E.end(),[](const auto& e,const auto& f){
		return get<2>(e)<get<2>(f);
	});

	T total{};
	union_find U(n);
	for(const auto& [u,v,wt]:E){
		if(!U.is_same(u,v)){
			U.unite(u,v);
			total+=wt;
		}
	}
	return total;
}

template<class M>
class segment_tree{
	int n,sz;
	vector<M> seg;
public:
	segment_tree(int n=0){ build(n); }
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

template<class T> class min_monoid;
template<class T1,class T2>
class min_monoid<pair<T1,T2>>{
	pair<T1,T2> a;
public:
	min_monoid():a(numeric_limits<T1>::max(),numeric_limits<T2>::max()){}
	min_monoid(const pair<T1,T2>& val):a(val){}
	min_monoid operator*(const min_monoid& x)const{
		return min(a,x.a);
	}
	pair<T1,T2>& get(){ return a; }
	const pair<T1,T2>& get()const{ return a; }
};

const long long INF=1LL<<61;

int main(){
	int n;
	lint d; scanf("%d%lld",&n,&d);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return a[i]<a[j];
	});

	vector<tuple<int,int,lint>> E;
	segment_tree<min_monoid<pair<lint,int>>> SL(n),SR(n);
	for(int u:p){
		int v;
		lint c;
		tie(c,v)=SL.product(0,u).get();
		if(c<INF) E.emplace_back(u,v,a[u]+a[v]+d*(u-v));
		tie(c,v)=SR.product(u,n).get();
		if(c<INF) E.emplace_back(u,v,a[u]+a[v]+d*(v-u));
		SL.update(u,make_pair(a[u]+(n-u-1)*d,u));
		SR.update(u,make_pair(a[u]+d*u,u));
	}
	printf("%lld\n",Kruskal(n,E));

	return 0;
}
