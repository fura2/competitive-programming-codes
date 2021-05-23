#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	static mint dp[2][6001]; // dp[i+1][j] = (a[i] まで見て, 1 を j 個選んだときの場合の数)
	dp[0][0]=1;
	rep(i,n){
		int cur=i%2,next=(i+1)%2;
		rep(j,n+1) dp[next][j]=0;

		rep(j,i+1){
			dp[next][j+1]+=dp[cur][j];
			dp[next][j]+=(a[i]-1)*dp[cur][j];
		}

		rep(j,n+1) dp[cur][j]=dp[next][j];
	}

	rep(_,q){
		int b; scanf("%d",&b);
		printf("%d\n",dp[n%2][b].to_int());
	}

	return 0;
}
