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

mint fact(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		for(;k<=n;k++) memo[k]=memo[k-1]*k;
	}
	return memo[n];
}

mint fact_inverse(int n){
	static vector<mint> memo={1};
	if(memo.size()<=n){
		int k=memo.size();
		memo.resize(n+1);
		memo[n]=inverse(fact(n));
		for(int i=n;i>k;i--) memo[i-1]=memo[i]*i;
	}
	return memo[n];
}

mint choose(int n,int k,int type=0){
	if(k<0 || n<k) return 0;
	if(type==0){
		return fact(n)*fact_inverse(k)*fact_inverse(n-k);
	}
	else{
		if(k>n-k) k=n-k;
		mint res=fact_inverse(k);
		rep(i,k) res*=n-i;
		return res;
	}
}

int main(){
	int n,m,p,q,r; scanf("%d%d%d%d%d",&n,&m,&p,&q,&r);

	p=(p+n)%m;
	q=(q+n)%m;
	r=(r+n)%m;

	int c=(p+q-r)%m;
	if(c<0) c+=m;

// O(n^3) solution
/*
	mint ans=0;
	rep(i,n+1) rep(j,n+1) rep(k,n+1) {
		if((i+j)%m==p
		&& (i+k)%m==q
		&& (j+k)%m==r) ans+=choose(n,i)*choose(n,j)*choose(n,k);
	}
	cout<<ans<<'\n';
*/

// O(n^2) solution
/*
	mint ans=0;
	rep(i,n+1) if(2*i%m==c) {
		mint tmp1=0,tmp2=0;
		rep(j,n+1) if(j%m==((p-i)%m+m)%m) tmp1+=choose(n,j);
		rep(k,n+1) if(k%m==((q-i)%m+m)%m) tmp2+=choose(n,k);
		ans+=choose(n,i)*tmp1*tmp2;
	}
	cout<<ans<<'\n';
*/

	vector<mint> bsum(m);
	rep(i,n+1) bsum[i%m]+=choose(n,i);

	mint ans=0;
	rep(i,n+1) if(2*i%m==c) ans+=choose(n,i)*bsum[((p-i)%m+m)%m]*bsum[((q-i)%m+m)%m];
	cout<<ans<<'\n';

	return 0;
}
