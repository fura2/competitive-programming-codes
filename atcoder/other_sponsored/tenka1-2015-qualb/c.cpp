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

mint floor_sum(long long n,long long m,long long a,long long b){
	mint res=0;
	if(a>=m){
		res+=mint(n)*(n-1)/2*(a/m);
		a%=m;
	}
	if(b>=m){
		res+=mint(n)*(b/m);
		b%=m;
	}

	long long y_max=(a*(n-1)+b)/m;
	if(y_max==0) return res;
	return res+y_max+floor_sum(y_max,a,m,(a*(n-1)+b)-m*y_max);
}

// 項数 n, 初項 a, 公差 d の等差数列の和
mint f(lint n,lint a,lint d){
	return n*(2*a+mint(n-1)*d)/2;
}

int main(){
	lint L; scanf("%lld",&L);

	if(L==5){
		puts("0");
		return 0;
	}

	// a+1 = b, b+1 = c
	mint ans=L/3-2;

	// a+1 = b, b+1 < c
	ans+=1;
	ans+=f((L+2)/3-2,L-6,-3);
	ans-=f((L+2)/4-1,L-5,-4);

	// a+1 < b, b+1 = c
	lint R=(L+2)/3-2;
	ans+=floor_sum(R-1,2,3,L-3*R-3);

	cout<<ans<<'\n';

// naive
/*
	mint res1=L/3-2,res2=1,res3=0;
	for(int x=1;x<=(L+2)/3-2;x++) res2+=L-(3*x+3);
	for(int x=1;x<=(L+2)/4-1;x++) res2-=L-(4*x+1);
	for(int x=2;x<=(L+2)/3-2;x++) res3+=(L-(3*x+3))/2;
	cout<<res1+res2+res3<<'\n';
*/

	return 0;
}
