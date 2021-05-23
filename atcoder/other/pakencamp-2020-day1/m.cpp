#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

template<class M>
vector<M> zeta_subset(vector<M> f){
	int n=log2(f.size());
	rep(i,n) rep(S,1<<n) if(~S>>i&1) f[S|1<<i]=f[S|1<<i]*f[S];
	return f;
}

int main(){
	int n; scanf("%d",&n);

	vector<or_monoid<int>> x(1<<20);
	rep(i,n){
		int a; scanf("%d",&a);
		x[a]=a;
	}

	x=zeta_subset(x);

	int ans=0;
	rep(S,1<<20) if(S!=0 && x[S].get()==S) ans++;
	printf("%d\n",ans);

	return 0;
}
