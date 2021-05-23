#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e5;
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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	static mint dp[2][2][1<<20]; // [i,j][一つ右が O かどうか][1 行下にある I の位置]
	dp[0][0][0]=1;
	for(int i=h-1;i>=0;i--) for(int j=w-1;j>=0;j--) {
		rep(k,2) rep(S,1<<w) dp[1][k][S]=0;

		rep(S,1<<w){
			if(B[i][j]=='?' || B[i][j]=='J'){
				if(j<w-1 && S>>j&1){ // 一つ右が O かつ一つ下が I 
					dp[1][0][S&~(1<<j)]+=dp[0][0][S];
				}
				else{
					dp[1][0][S&~(1<<j)]+=dp[0][0][S]+dp[0][1][S];
				}
			}
			if(B[i][j]=='?' || B[i][j]=='O'){
				dp[1][1][S&~(1<<j)]+=dp[0][0][S]+dp[0][1][S];
			}
			if(B[i][j]=='?' || B[i][j]=='I'){
				dp[1][0][S|(1<<j)]+=dp[0][0][S]+dp[0][1][S];
			}
		}

		rep(k,2) rep(S,1<<w) dp[0][k][S]=dp[1][k][S];
	}

	int cnt=0;
	rep(i,h) rep(j,w) if(B[i][j]=='?') cnt++;

	mint ans=pow(mint(3),cnt);
	rep(k,2) rep(S,1<<w) ans-=dp[0][k][S];
	cout<<ans<<'\n';

	return 0;
}
