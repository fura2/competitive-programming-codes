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
	mint& operator*=(const mint& m){ x=(long long)x*m.x%MOD; return *this; }
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
	if(k==0) return 1;
	if(n< k) return 0;
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

mint root[24]; // root[i] = (mod 998244353 における 1 の 2^i 乗根)
mint root_inverse[24];

void NTT(vector<mint>& f,bool inverse=false){
	int n=f.size();

	if(n==1) return;

	vector<mint> f1(n/2),f2(n/2);
	rep(i,n/2){
		f1[i]=f[2*i];
		f2[i]=f[2*i+1];
	}

	NTT(f1,inverse);
	NTT(f2,inverse);

	int e=log2(n);
	mint omega=(!inverse?root[e]:root_inverse[e]);
	mint coef=1;
	rep(i,n){
		f[i]=f1[i%(n/2)]+coef*f2[i%(n/2)];
		coef*=omega;
	}
}

vector<mint> convolution(vector<mint> f,vector<mint> g){
	int n=f.size(),m=g.size();
	int k;
	for(k=1;k<n+m-1;k*=2);

	f.resize(k);
	g.resize(k);
	NTT(f);
	NTT(g);

	rep(i,f.size()) f[i]*=g[i];

	NTT(f,true);
	f.resize(n+m-1);
	mint coef=mint(1)/k;
	rep(i,f.size()) f[i]*=coef;

	return f;
}

int main(){
	root[23]=pow(mint(3),119);
	for(int i=22;i>=0;i--){
		root[i]=root[i+1]*root[i+1];
	}
	rep(i,24) root_inverse[i]=1/root[i];

	int r,g,b,k,x,y,z;
	cin>>r>>g>>b>>k>>x>>y>>z;

	int n=r+g+b+1;
	vector<mint> f1(n),f2(n),f3(n);
	for(int i=k-y;i<=r;i++) f1[i]=choose(r,i);
	for(int i=k-z;i<=g;i++) f2[i]=choose(g,i);
	for(int i=k-x;i<=b;i++) f3[i]=choose(b,i);

	cout<<convolution(convolution(f1,f2),f3)[k]<<'\n';

	return 0;
}
