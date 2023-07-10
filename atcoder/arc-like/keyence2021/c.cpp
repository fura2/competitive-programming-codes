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
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	vector<string> B(h,string(w,'.'));
	rep(i,k){
		int x,y;
		char c; scanf("%d%d %c",&x,&y,&c); x--; y--;
		B[x][y]=c;
	}

	vector cum(h+1,vector(w+1,0));
	rep(i,h) rep(j,w) cum[i+1][j+1]=cum[i+1][j]+cum[i][j+1]-cum[i][j]+(B[i][j]=='.'?1:0);

	vector three(h+w+1,mint(0));
	three[0]=1;
	rep(i,h+w) three[i+1]=three[i]*3;

	vector dp(h,vector(w,mint(0)));
	dp[0][0]=1;
	rep(i,h) rep(j,w) {
		if(i>0){
			int coef;
			if     (B[i-1][j]=='.') coef=2;
			else if(B[i-1][j]=='R') coef=0;
			else                    coef=1;
			dp[i][j]+=dp[i-1][j]*coef*three[cum[i+1][j]-cum[i][j]];
		}
		if(j>0){
			int coef;
			if     (B[i][j-1]=='.') coef=2;
			else if(B[i][j-1]=='D') coef=0;
			else                    coef=1;
			dp[i][j]+=dp[i][j-1]*coef*three[cum[i][j+1]-cum[i][j]];
		}
	}

	mint ans=dp[h-1][w-1];
	if(B[h-1][w-1]=='.') ans*=3;
	cout<<ans<<'\n';

	return 0;
}
