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

mint solve(int a,int b){
	int n=a+b;

	mint memo[301][301][301];
	bool vis[301][301][301]={};

	// k : 位置決めを保留にした i の個数
	// l : p_i<i となる i の個数
	auto dfs=[&](auto&& dfs,int i,int k,int l)->mint{
		if(k<0 || l>a) return 0;

		if(vis[i][k][l]) return memo[i][k][l];
		vis[i][k][l]=true;

		mint& res=memo[i][k][l];
		if(i==n) return res=(k==0&&l==a?1:0);

		// i を自身より左に置き, 保留にしていた数を i 番目に置く
		res+=dfs(dfs,i+1,k-1,l+1)*k*k;
		// i を自身より左に置き, i 番目に何も置かない
		res+=dfs(dfs,i+1,k,l+1)*k;
		// i の位置決めを保留にし, 保留にしていた数を i 番目に置く
		res+=dfs(dfs,i+1,k,l)*k;
		// i の位置決めを保留にし, i 番目に何も置かない
		res+=dfs(dfs,i+1,k+1,l);
		return res;
	};
	return dfs(dfs,0,0,0);
}

int main(){
	int n,a,b; cin>>n>>a>>b;
	cout<<choose(n,n-a-b)*solve(a,b)<<'\n';
	return 0;
}
