#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return mint(-x); }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	if(count(a.begin(),a.end(),0)>0) return puts("0"),0;

	vector<lint> cum(n+2);
	lint prod=1;
	for(int l=0,r=0;l<n;l++){
		while(r<n && prod*a[r]<lint(1e9)) prod*=a[r], r++;
		cum[l]+=r-l;
		cum[l+1]-=r-l+1;
		cum[r+1]++;
		prod/=a[l];
	}
	rep(i,n+1) cum[i+1]+=cum[i];
	rep(i,n+1) cum[i+1]+=cum[i];

	mint ans=1;
	rep(i,n) ans*=pow(mint(a[i]),cum[i]);
	cout<<ans<<'\n';

	return 0;
}
