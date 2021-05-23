#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(int n):a(n){}
	void add(int i,G val){
		for(i++;i<=a.size();i+=i&-i) a[i-1]+=val;
	}
	G sum(int l,int r)const{
		if(l==0){
			G res{};
			for(;r>0;r-=r&-r) res+=a[r-1];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
	int lower_bound(G val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

class permutation{
	vector<int> f;
public:
	permutation(){}
	permutation(int n){
		f.resize(n);
		iota(f.begin(),f.end(),0);
	}
	permutation(const vector<int>& p):f(p){}

	permutation operator*(const permutation& p)const{
		int n=f.size();
		permutation res(n);
		rep(i,n) res.f[i]=f[p[i]];
		return res;
	}
	int operator[](int i)const{ return f[i]; }

	int size()const{ return f.size(); }

	friend permutation inverse(const permutation& p){
		int n=p.f.size();
		permutation res(n);
		rep(i,n) res.f[p.f[i]]=i;
		return res;
	}
};

long long inversion_number(const permutation& p){
	int n=p.size();
	long long res=0;
	Fenwick_tree<int> F(n);
	rep(i,n){ res+=F.sum(p[i]+1,n); F.add(p[i],1); }
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> p(n);
	rep(i,n) scanf("%d",&p[i]), p[i]--;
	printf("%lld\n",inversion_number(permutation(p)));
	return 0;
}
