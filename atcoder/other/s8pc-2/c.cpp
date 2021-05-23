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

int main(){
	string s;
	int m; cin>>s>>m;
	int n=s.length();

	vector val(n,vector(n+1,0)); // val[l][r] = (s[l,r) を整数として読んだもの)
	rep(l,n) for(int r=l+1;r<=n;r++) {
		val[l][r]=min(10*val[l][r-1]+(s[r-1]-'0'),m+1);
	}

	vector dp(n+1,vector(m+1,mint(0)));
	dp[0][0]=1;
	rep(i,n){
		for(int j=i;j>=0;j--){
			rep(d,m-val[j][i+1]+1){
				dp[i+1][d+val[j][i+1]]+=dp[j][d];
			}
		}
	}
	cout<<accumulate(dp[n].begin(),dp[n].end(),mint(0))<<'\n';

	return 0;
}
