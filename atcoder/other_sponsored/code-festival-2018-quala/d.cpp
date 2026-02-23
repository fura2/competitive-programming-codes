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

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

int main(){
	int d,L1,L2,n; cin>>d>>L2>>L1>>n;
	L1=L2-L1;
	vector<int> x(n+1);
	rep(i,n) cin>>x[i+1];

/*
	// O(n^3) DP
	// dp[i] = (x[0..i] を使うかどうか決めて最後に x[i] で補給したときの選び方の総数)
	vector<mint> dp(n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		rep(j,i){
			if(L1<x[i]-x[j] && x[i]-x[j]<=L2){
				int cnt=0;
				for(int k=j+1;k<i;k++){
					if(x[k]-x[j]<=L1){
						cnt++;
					}
				}
				dp[i]+=pow(mint(2),cnt)*dp[j];
			}
		}
	}

	mint ans=0;
	rep(i,n+1) if(d-x[i]<=L2) {
		int cnt=0;
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=L1){
				cnt++;
			}
		}
		ans+=pow(mint(2),cnt)*dp[i];
	}
	cout<<ans<<'\n';
*/

	vector<int> a(n+1);
	rep(i,n+1){
		a[i]=upper_bound(x.begin(),x.end(),x[i]+L1)-(x.begin()+i)-1;
	}

	vector<mint> dp1(n+1),dp2(n+2);
	dp1[0]=1;
	dp2[1]=pow(mint(2),a[0]);
	for(int i=1;i<=n;i++){
		int l=lower_bound(x.begin(),x.end(),x[i]-L2)-x.begin();
		int r=lower_bound(x.begin(),x.end(),x[i]-L1)-x.begin();
		dp1[i]=dp2[r]-dp2[l];
		dp2[i+1]=dp2[i]+pow(mint(2),a[i])*dp1[i];
	}

	mint ans=0;
	rep(i,n+1) if(d-x[i]<=L2) {
		ans+=pow(mint(2),a[i])*dp1[i];
	}
	cout<<ans<<'\n';

	return 0;
}
