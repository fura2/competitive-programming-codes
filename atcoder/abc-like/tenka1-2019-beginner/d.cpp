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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int sum=accumulate(a.begin(),a.end(),0);

	mint dp[2][90001];
	dp[0][0]=1;
	rep(i,n){
		int curr=i%2,next=(i+1)%2;
		rep(j,sum+1) dp[next][j]=0;

		rep(j,sum+1) dp[next][j]=2*dp[curr][j];
		rep(j,sum-a[i]+1) dp[next][j+a[i]]+=dp[curr][j];

		rep(j,sum+1) dp[curr][j]=dp[next][j];
	}

	mint dp2[90001];
	dp2[0]=1;
	rep(i,n) for(int j=sum;j>=a[i];j--) dp2[j]+=dp2[j-a[i]];

	mint res=0;
	for(int j=(sum+1)/2;j<=sum;j++) res+=3*dp[n%2][j];
	if(sum%2==0) res-=3*dp2[sum/2];
	cout<<pow(mint(3),n)-res<<'\n';

	return 0;
}
