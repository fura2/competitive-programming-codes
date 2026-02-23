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
	int L,n; scanf("%d%d",&L,&n);
	static bool ng[2][3000001];
	rep(i,n){
		int t,x; scanf("%d%d",&t,&x);
		ng[t-1][x]=true;
	}

	// dp[0][x] = 往路も復路も x にいる場合の数
	// dp[1][x] = 往路は x に, 復路は x-1 にいる場合の数
	// dp[2][x] = 往路は x-1 に, 復路は x にいる場合の数
	static mint dp[3][3000001];
	dp[0][0]=1;
	for(int x=1;x<=L;x++){
		if(!ng[0][x] && !ng[1][x]){
			dp[0][x]+=dp[0][x-1]+dp[1][x-1]+dp[2][x-1];
		}
		if(!ng[0][x] && !ng[1][x-1]){
			dp[1][x]+=dp[0][x-1]+dp[2][x-1];
		}
		if(!ng[0][x-1] && !ng[1][x]){
			dp[2][x]+=dp[0][x-1]+dp[1][x-1];
		}
	}
	printf("%d\n",dp[0][L].to_int());

	return 0;
}
