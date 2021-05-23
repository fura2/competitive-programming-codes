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

mint fact(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=memo[k-1]*k;
	}
	return memo[n];
}

inline int popcount(long long x){
	x-=(x>>1)&0x5555555555555555LL;
	x=(x&0x3333333333333333LL)+((x>>2)&0x3333333333333333LL);
	x=(x+(x>>4))&0x0f0f0f0f0f0f0f0fLL;
	x=(x*0x0101010101010101LL)>>56;
	return x;
}

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(k);
	rep(i,k) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	rep(i,k-1) if((a[i]&a[i+1])!=a[i]) return puts("0"),0;

	vector<int> cnt(k+2);
	cnt[0]=0;
	rep(i,k) cnt[i+1]=popcount(a[i]);
	cnt[k+1]=n;

	mint ans=1;
	rep(i,k+1) ans*=fact(cnt[i+1]-cnt[i]);
	cout<<ans<<'\n';

	return 0;
}
