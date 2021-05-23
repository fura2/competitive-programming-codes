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
	string s; cin>>s;
	int n=s.length();

	// dp1[i][c] = ( s[0,i) の部分列であって末尾の文字が c であるものの個数 )
	vector dp1(n+1,vector(26,mint(0)));
	rep(i,n){
		rep(c,26) dp1[i+1][c]=dp1[i][c];

		int c0=s[i]-'a';
		dp1[i+1][c0]+=1;
		rep(c,26) dp1[i+1][c0]+=dp1[i][c];
	}

	// dp2[i][c] = ( s[0,i) の部分列であって末尾の文字が c であるものについての連の個数の総和 )
	vector dp2(n+1,vector(26,mint(0)));
	rep(i,n){
		// s[i] を選ばない
		rep(c,26) dp2[i+1][c]=dp2[i][c];
		// s[i] を選ぶ
		int c0=s[i]-'a';
		dp2[i+1][c0]+=1; // s[i] のみからなる部分列
		rep(c,26){
			if(c==c0) dp2[i+1][c0]+=dp2[i][c];
			else      dp2[i+1][c0]+=dp2[i][c]+dp1[i][c];
		}
	}

	mint ans=0;
	rep(c,26) ans+=dp2[n][c];
	cout<<ans<<'\n';

	return 0;
}
