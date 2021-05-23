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

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

int main(){
	int n,p[1001],l[1001];
	scanf("%d",&n);
	p[0]=-2000; l[0]=0;
	rep(i,n) scanf("%d%d",&p[i+1],&l[i+1]);

	mint dp[1001][2001];
	dp[0][0]=1;
	rep(i,n){
		for(int d=-l[i+1];d<=l[i+1];d++){
			int x=p[i+1]+d;
			if(x<=p[i]-l[i]) continue;
			dp[i+1][d+l[i+1]]+=dp[i][max(min(x-1,p[i]+l[i]),p[i]-l[i])-(p[i]-l[i])];
			if(d>-l[i+1]) dp[i+1][d+l[i+1]]+=dp[i+1][d+l[i+1]-1];
		}
	}
	printf("%d\n",dp[n][2*l[n]].to_int());

	return 0;
}
