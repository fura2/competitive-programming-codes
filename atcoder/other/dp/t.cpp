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
	int n;
	string s; cin>>n>>s;
	s="<"+s;

	// dp[i][j] = 左から i 個目まで決めて, 最後に置いた数より大きい数が j 個残っているような置き方の数
	static mint dp[3001][3001];
	dp[0][n]=1;
	rep(i,n){
		rep(j,n-i+1){
			if(s[i]=='<'){
				dp[i+1][0]+=dp[i][j];
				dp[i+1][j]-=dp[i][j];
			}
			else{
				dp[i+1][j]+=dp[i][j];
				dp[i+1][n-i]-=dp[i][j];
			}
		}
		rep(j,n) dp[i+1][j+1]+=dp[i+1][j];
	}
// O(n^3) DP
/*
	rep(i,n){
		rep(j,n-i+1){
			if(s[i]=='<'){
				rep(k,j) dp[i+1][k]+=dp[i][j];
			}
			else{
				rep(k,n-i-j) dp[i+1][k+j]+=dp[i][j];
			}
		}
	}
*/
	cout<<dp[n][0]<<'\n';

	return 0;
}
