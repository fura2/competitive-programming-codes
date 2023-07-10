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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int m=0;
	rep(i,h) rep(j,w) if(B[i][j]=='.') m++;

	vector U(h,vector(w,0));
	vector L(h,vector(w,0));
	vector D(h,vector(w,0));
	vector R(h,vector(w,0));
	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		U[i][j]=(i==0?0:U[i-1][j])+1;
		L[i][j]=(j==0?0:L[i][j-1])+1;
	}
	for(int i=h-1;i>=0;i--) for(int j=w-1;j>=0;j--) if(B[i][j]=='.') {
		D[i][j]=(i==h-1?0:D[i+1][j])+1;
		R[i][j]=(j==w-1?0:R[i][j+1])+1;
	}

	mint ans=0;
	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		int k=U[i][j]+L[i][j]+D[i][j]+R[i][j]-3;
		ans+=(pow(mint(2),k)-1)*pow(mint(2),m-k);
	}
	cout<<ans<<'\n';

	return 0;
}
