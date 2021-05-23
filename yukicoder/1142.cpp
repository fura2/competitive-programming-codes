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
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,m) scanf("%d",&b[j]);

	auto calc=[](vector<int> a){
		int n=a.size();
		vector<int> cum(n+1);
		rep(i,n) cum[i+1]=cum[i]^a[i];

		vector<mint> cnt(1024);
		rep(i,n+1) cnt[cum[i]]+=1;

		vector<mint> res(1024);
		rep(x,1024){
			res[0]+=cnt[x]*(cnt[x]-1)/2;
			for(int y=x+1;y<1024;y++){
				res[x^y]+=cnt[x]*cnt[y];
			}
		}
		return res;
	};

	auto res1=calc(a);
	auto res2=calc(b);

	mint ans=0;
	rep(x,1024) ans+=res1[x]*res2[k^x];
	cout<<ans<<'\n';

	return 0;
}
