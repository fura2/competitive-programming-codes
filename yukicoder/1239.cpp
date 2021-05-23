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

bool operator<(const mint& x,const mint& y){ return x.to_int()<y.to_int(); }

int n,a[200000];
mint two[200000];

mint solve(int p){
	rep(i,n) if(a[i]==0 || abs(a[i])>2) a[i]=p;

	mint res=0,cum=1;
	map<mint,mint> f;
	f[1]=1;
	rep(i,n){
		cum*=a[i];
		f[cum]+=two[i];
		res+=f[cum/(-2)]*two[i==n-1?0:n-i-2];
	}
	return res/two[n-1];
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	two[0]=1;
	rep(i,n-1) two[i+1]=two[i]*2;

	map<mint,int> f;
	++f[solve(3)];
	++f[solve(5)];
	++f[solve(7)];
	++f[solve(11)];
	++f[solve(13)];

	mint ans;
	int best=0;
	for(auto [x,c]:f) if(c>best) ans=x, best=c;
	cout<<ans<<'\n';

	return 0;
}
