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

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n){
		lint x; scanf("%lld",&x);
		while(x>0) a[i]++, x/=2;
	}
	k=min(k,60*n);

	// dp[i+1][j][b] = (a[i] まで見て, あと j 回操作できる状態での作れる列の個数)
	//                  b : 0 を一つ以上作ったかどうか
	mint dp[51][60*50+1][2];
	dp[0][k][0]=1;
	rep(i,n){
		rep(j,60*n+1){
			rep(l,min(a[i],j)+1){
				if(l==a[i]){ // 0 を作る
					dp[i+1][j-l][1]+=dp[i][j][0]+dp[i][j][1];
				}
				else{
					dp[i+1][j-l][0]+=dp[i][j][0];
					dp[i+1][j-l][1]+=dp[i][j][1];
				}
			}
		}
	}

	mint ans=dp[n][0][0];
	rep(j,k+1) ans+=dp[n][j][1];
	cout<<ans<<'\n';

	return 0;
}
