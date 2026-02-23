#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7;
//	static const int MOD=998244353;
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
	vector<int> x(k),y(k);
	rep(i,k) scanf("%d%d",&y[i],&x[i]), x[i]--, y[i]--;

	bool B1[1000][1000]={},B2[1000][1000]={};
	rep(i,k){
		if(x[i]+2<h && y[i]-1>=0) B1[x[i]+2][y[i]-1]=true;
		if(x[i]-1>=0 && y[i]+2<w) B2[x[i]-1][y[i]+2]=true;
	}
	rep(i,h) for(int j=w-2;j>=0;j--) {
		B1[i][j]|=B1[i][j+1];
	}
	for(int j=w-1;j>=0;j--) for(int i=1;i<h;i++) {
		B1[i][j]|=B1[i-1][j];
	}
	for(int i=h-1;i>=0;i--) for(int j=1;j<w;j++) {
		B2[i][j]|=B2[i][j-1];
	}
	rep(j,w) for(int i=h-2;i>=0;i--) {
		B2[i][j]|=B2[i+1][j];
	}

	vector dp(h,vector(w,mint(0)));
	dp[0][0]=1;
	rep(i,h) rep(j,w) if(!B1[i][j] && !B2[i][j]) {
		if(i<h-1 && !B1[i+1][j] && !B2[i+1][j]) dp[i+1][j]+=dp[i][j];
		if(j<w-1 && !B1[i][j+1] && !B2[i][j+1]) dp[i][j+1]+=dp[i][j];
	}
	cout<<dp[h-1][w-1]<<'\n';

	return 0;
}
