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

int n,k,l;
bool vis[366][1<<12];
mint memo[366][1<<12];

mint dfs(int i,int S){
	if(vis[i][S]) return memo[i][S];
	vis[i][S]=true;
	mint& res=memo[i][S];

	if(i==n) return res=1;

	res=0;
	for(int T=1;T<8;T++){
		int S2=(S<<3)|T;

		int cnt[3]={};
		rep(j,3*k) if(S2>>j&1) cnt[j%3]++;

		bool ok=true;
		rep(j,3) if(cnt[j]>l) ok=false;
		if(ok){
			res+=dfs(i+1,S2&((1<<3*(k-1))-1));
		}
	}
	return res;
}

int main(){
	cin>>n>>k>>l;
	cout<<dfs(0,0)<<'\n';
	return 0;
}
