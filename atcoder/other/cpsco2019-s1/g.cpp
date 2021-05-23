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

int main(){
	int n; scanf("%d",&n);

	segment_tree<max_monoid<lint>> S(vector(1e6+1,0LL));
	rep(_,n){
		int a; scanf("%d",&a);

		vector<int> B;
		for(int b=1;b*b<=a;b++){
			B.emplace_back(b);
			B.emplace_back(a/b);
		}
		sort(B.begin(),B.end());
		B.erase(unique(B.begin(),B.end()),B.end());

		vector<lint> next;
		for(int b:B){
			int l=a/(b+1)+1;
			int r=a/b+1;
			next.emplace_back(S.get(l,r).get()+b);
		}
		rep(i,B.size()){
			S.update(B[i],max(S[B[i]].get(),next[i]));
		}
	}
	printf("%lld\n",S.get(0,1e6+1));

	return 0;
}
