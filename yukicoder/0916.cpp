#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

int main(){
	int d,l,r,k; scanf("%d%d%d%d",&d,&l,&r,&k);

	int hl=0,hr=0; // l の深さ, r の深さ
	while((1<<(hl+1))<=l) hl++;
	while((1<<(hr+1))<=r) hr++;

	// 深さ t の頂点まで上がる
	int t;
	for(t=0;t<=hl;t++) if(hr-hl+2*(hl-t)==k) break;
	if(t>hl) return puts("0"),0;

	mint ans=1;
	rep(i,d) ans*=fact(1<<i);
	if(hl==hr){
		ans*=1<<(hl-t-1);
		ans/=(1<<hl)-1;
	}
	else{
		if(t==hl){
			ans*=1<<(hr-hl);
			ans/=1<<hr;
		}
		else{
			ans*=1<<(hr-t-1);
			ans/=1<<hr;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
