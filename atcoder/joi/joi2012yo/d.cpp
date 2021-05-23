#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e4;
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

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n,-1);
	rep(i,k){
		int x,b; scanf("%d%d",&x,&b); x--; b--;
		a[x]=b;
	}

	mint dp[100][3][3];
	rep(j1,3) if(a[1]==-1 || a[1]==j1) {
		rep(j2,3) if(a[0]==-1 || a[0]==j2) {
			dp[0][j1][j2]=1;
		}
	}
	for(int i=2;i<n;i++){
		rep(j0,3) if(a[i]==-1 || a[i]==j0) rep(j1,3) rep(j2,3) if(j0!=j1 || j0!=j2) {
			dp[i-1][j0][j1]+=dp[i-2][j1][j2];
		}
	}

	mint ans=0;
	rep(j1,3) rep(j2,3) ans+=dp[n-2][j1][j2];
	cout<<ans<<'\n';

	return 0;
}
