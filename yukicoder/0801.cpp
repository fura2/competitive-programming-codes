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
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<int> l(m),r(m);
	rep(j,m) scanf("%d%d",&l[j],&r[j]), l[j]--;

	vector dp(2,vector(n+1,mint(0)));
	dp[0][0]=1;
	rep(t,k){
		int curr=t%2,next=(t+1)%2;
		rep(i,n+1) dp[next][i]=0;

		vector cum(n+1,mint(0));
		rep(i,n) cum[i+1]=cum[i]+dp[curr][i];

		rep(j,m){
			dp[next][l[j]]+=cum[r[j]]-cum[l[j]];
			dp[next][r[j]]-=cum[r[j]]-cum[l[j]];
		}
		rep(i,n) dp[next][i+1]+=dp[next][i];

		dp[curr]=dp[next];
	}
	printf("%d\n",dp[k%2][n-1].to_int());

	return 0;
}
