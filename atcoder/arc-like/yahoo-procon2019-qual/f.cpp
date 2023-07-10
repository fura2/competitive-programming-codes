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
	string s; cin>>s;
	int n=s.length();

	vector<int> nr(n+1),nb(n+1);
	rep(i,n){
		if     (s[i]=='0') nr[i+1]=2;
		else if(s[i]=='1') nr[i+1]=1, nb[i+1]=1;
		else               nb[i+1]=2;
	}
	rep(i,n){
		nr[i+1]+=nr[i];
		nb[i+1]+=nb[i];
	}

	static mint dp[4001][4001]; // dp[r][b] = 赤を r 個, 青を b 個並べてできる列の個数
	dp[0][0]=1;
	rep(i,2*n){
		rep(r,i+1){
			int b=i-r;
			if(r<=nr[min(i,n)] && b<=nb[min(i,n)]){
				if(r+1<=nr[min(i+1,n)]) dp[r+1][b]+=dp[r][b];
				if(b+1<=nb[min(i+1,n)]) dp[r][b+1]+=dp[r][b];
			}
		}
	}

	mint ans=0;
	rep(r,2*n+1) ans+=dp[r][2*n-r];
	cout<<ans<<'\n';

	return 0;
}
