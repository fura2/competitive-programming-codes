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

int main(){
	int n; scanf("%d",&n);

	// dp[i][j][k] = (i 組目まで見て, 条件をみたすグループが j 個, 条件をみたさないグループが k 個できる場合の数)
	mint dp[2][560][560];
	dp[0][0][0]=1;
	rep(i,n){
		int curr=i%2,next=(i+1)%2;
		rep(j,i+1) rep(k,n+1) dp[next][j][k]=0;

		rep(j,i+1) rep(k,n+1) {
			if(2*j+k>2*i) break;
			// 2 人で一緒に新しくグループを作る
			dp[next][j+1][k]+=dp[curr][j][k];
			// 2 人別々に新しくグループを作る
			dp[next][j][k+2]+=dp[curr][j][k];
			// 1 人は新しくグループを作り, もう 1 人はすでにあるグループに混ざる
			dp[next][j][k+1]+=2*(j+k)*dp[curr][j][k];
			// 2 人一緒にすでにあるグループに混ざる
			dp[next][j][k]+=j*dp[curr][j][k];
			if(k>0) dp[next][j+1][k-1]+=k*dp[curr][j][k];
			// 2 人別々にすでにあるグループに混ざる
			dp[next][j][k]+=(j+k)*(j+k-1)*dp[curr][j][k];
		}

		rep(j,i+1) rep(k,n+1) dp[curr][j][k]=dp[next][j][k];
	}

	mint ans=0;
	rep(j,n+1) ans+=dp[n%2][j][0];
	cout<<ans<<'\n';

	return 0;
}
