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

mint fact(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=memo[k-1]*k;
	}
	return memo[n];
}

int main(){
	int n; scanf("%d",&n);
	vector<int> l(n),r(n);
	rep(i,n) scanf("%d%d",&l[i],&r[i]);

	vector<int> X;
	rep(i,n){
		X.emplace_back(l[i]);
		X.emplace_back(r[i]);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	int m=X.size();

	// coef[j] = (max の累積分布関数 F(x) の x^j の係数)
	vector<mint> coef(n+1);
	coef[0]=1;

	mint ans=X.back();
	int cnt=0;
	rep(k,m-1){ // [X[k], X[k+1])
		rep(i,n){ // [l[i], r[i])
			if(l[i]==X[k]){
				// * (x-l[i])/(r[i]-l[i])
				for(int j=n;j>=0;j--){
					coef[j]*=-l[i];
					if(j>0) coef[j]+=coef[j-1];
				}
				rep(j,n+1) coef[j]/=r[i]-l[i];
				cnt++;
			}
			else if(r[i]==X[k]){
				// / (x-l[i])/(r[i]-l[i])
				rep(j,n+1) coef[j]*=r[i]-l[i];
				rep(j,n+1){
					if(j>0) coef[j]-=coef[j-1];
					coef[j]/=-l[i];
				}
			}
		}

		if(cnt==n){
			rep(j,n+1){
				ans-=coef[j]/(j+1)*(pow(mint(X[k+1]),j+1)-pow(mint(X[k]),j+1));
			}
		}
	}

	ans*=fact(n+1);
	rep(i,n) ans*=r[i]-l[i];

	cout<<ans<<'\n';

	return 0;
}
