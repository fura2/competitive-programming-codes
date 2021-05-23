#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class mint{
	static const int MOD=998244353;
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
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	vector<string> B(h,string(w,'.'));
	rep(i,k){
		int x,y;
		char c; scanf("%d%d %c",&x,&y,&c); x--; y--;
		B[x][y]=c;
	}

	mint C=mint(2)/3;

	vector dp(h,vector(w,mint(0)));
	dp[0][0]=1;
	rep(i,h) rep(j,w) {
		if(i>0 && B[i-1][j]!='R') dp[i][j]+=(B[i-1][j]=='.'?C:1)*dp[i-1][j];
		if(j>0 && B[i][j-1]!='D') dp[i][j]+=(B[i][j-1]=='.'?C:1)*dp[i][j-1];
	}

	cout<<dp[h-1][w-1]*pow(mint(3),lint(h)*w-k)<<'\n';

	return 0;
}
