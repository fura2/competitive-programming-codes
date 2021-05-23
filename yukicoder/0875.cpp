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
	M get(int l,int r)const{
		M lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*seg[a++];
			if(b&1) rcum=seg[--b]*rcum;
		}
		return lcum*rcum;
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

int main(){
	int n,q; scanf("%d%d",&n,&q);

	vector<pair<int,int>> a(n);
	rep(i,n){
		int b; scanf("%d",&b); b--;
		a[i]=make_pair(b,i);
	}
	segment_tree<min_monoid<pair<int,int>>> S(a);

	rep(_,q){
		int type,l,r; scanf("%d%d%d",&type,&l,&r);
		if(type==1){
			l--; r--;
			int tmpl=S[l].get().first;
			int tmpr=S[r].get().first;
			S.update(l,make_pair(tmpr,l));
			S.update(r,make_pair(tmpl,r));
		}
		else{
			l--;
			printf("%d\n",S.get(l,r).get().second+1);
		}
	}

	return 0;
}
