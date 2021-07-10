#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint modpow(lint a,lint k,int m){
	lint r=1%m;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

template<class M>
M pow(M f,long long k){
	M res;
	for(;k>0;k>>=1){
		if(k&1) res=res*f;
		f=f*f;
	}
	return res;
}

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=(long long)x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return -x; }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=t; return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

int m;

class monoid{
public:
	lint len;
	vector<mint> a; // a[i] = (len 桁の数のうち mod m で i に等しいものの個数)

	monoid():len(0),a(m){
		a[0]=1;
	}

	monoid operator*(const monoid& x)const{
		monoid res;
		res.len=len+x.len;
		rep(i,m) res.a[i]=0;

		int ten=modpow(10,x.len,m);
		rep(i,m){
			rep(j,m){
				res.a[(i*ten+j)%m]+=a[i]*x.a[j];
			}
		}
		return res;
	}
};

int main(){
	lint n;
	int k; scanf("%lld%d%d",&n,&m,&k);
	vector<int> c(k);
	rep(i,k) scanf("%d",&c[i]);

	monoid M;
	M.len=1;
	rep(i,m) M.a[i]=0;
	rep(i,k) M.a[c[i]%m]+=1;

	printf("%d\n",pow(M,n).a[0]);

	return 0;
}
