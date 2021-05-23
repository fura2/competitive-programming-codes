#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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

mint operator+(long long y,const mint& m){ return m+y; }
mint operator*(long long y,const mint& m){ return m*y; }

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> v(n),r(m);
	rep(i,n) scanf("%d",&v[i]);
	rep(j,m) scanf("%d",&r[j]);
	lint a,b; scanf("%lld%lld",&a,&b);

	mint dp1[100001]={1},dp2[100001]={1};
	rep(i,n) for(int w=1e5;w>=v[i];w--) dp1[w]+=dp1[w-v[i]];
	rep(j,m) for(int w=1e5;w>=r[j];w--) dp2[w]+=dp2[w-r[j]];

	rep(w,1e5) dp1[w+1]+=dp1[w];

	mint ans=0;
	for(int w=1;w<=1e5;w++) ans+=(dp1[min(b*w,100000LL)]-dp1[min(a*w-1,100000LL)])*dp2[w];
	cout<<ans<<'\n';

	return 0;
}
