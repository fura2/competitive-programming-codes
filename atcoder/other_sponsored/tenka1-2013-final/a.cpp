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
	int h,w; scanf("%d%d",&h,&w);

	// dp[i][j][S] = (マス (i,j) まで埋めて, 直前 W+1 マス分の埋め方が S であるときの埋め方の数)
	mint dp[15][15][1<<16];
	dp[0][0][0]=dp[0][0][1]=1;
	rep(i,h) rep(j,w) if(!(i==h-1 && j==w-1)) {
		rep(S,1<<(w+1)){
			int i2=i,j2=j+1,S2;
			if(j==w-1) i2++, j2=0;

			// (i,j) に置かない
			S2=(S<<1)&((1<<(w+1))-1);
			dp[i2][j2][S2]+=dp[i][j][S];

			// (i,j) に置く
			if(~S>>(w-1)&1 && (j2==0 || ~S>>w&1) && (j2==w-1 || ~S>>(w-2)&1) && (j2==0 || ~S&1)){
				S2|=1;
				dp[i2][j2][S2]+=dp[i][j][S];
			}
		}
	}

	mint ans=0;
	rep(S,1<<(w+1)) ans+=dp[h-1][w-1][S];
	ans-=1;
	cout<<ans<<'\n';

	return 0;
}
