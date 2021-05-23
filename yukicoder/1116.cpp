#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

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

mint g(int zero,int one){
	static map<pair<int,int>,mint> memo;
	if(memo.count({zero,one})>0) return memo[{zero,one}];

	mint res=0;
	rep(i,zero+1){
		res+=choose(zero,i)*fact(i+one/2-1)*pow(mint(2),one/2-1);
	}
	return memo[{zero,one}]=res;
}

int n,m;
vector<pair<int,int>> E;

mint f(int S){ // S に含まれるすべての辺を含む K_n のサイクルの個数を求める
	map<int,int> h;
	rep(i,m) if(S>>i&1) {
		auto [u,v]=E[i];
		if(h.count(u)==0) h[u]=h.size();
		if(h.count(v)==0) h[v]=h.size();
	}

	int N=h.size(),loop_cnt=0;
	vector<int> deg(N);
	union_find U(N);
	rep(i,m) if(S>>i&1) {
		auto [u,v]=E[i];
		u=h[u];
		v=h[v];
		deg[u]++;
		deg[v]++;
		if(U.is_same(u,v)) loop_cnt++;
		U.unite(u,v);
	}

	int zero=count(deg.begin(),deg.end(),0)+n-N;
	int one =count(deg.begin(),deg.end(),1);

	rep(u,N) if(deg[u]>=3) return 0;
	if(loop_cnt>=2) return 0;
	if(loop_cnt==1) return one==0?1:0;

	mint res;
	if(zero==n){
		res=0;
		for(int l=3;l<=n;l++){
			res+=choose(n,l)*fact(l-1);
		}
		res/=2;
	}
	else{
		res=g(zero,one);
		if(popcount(S)==1) res-=1;
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	E.resize(m);
	rep(i,m) scanf("%d%d",&E[i].first,&E[i].second), E[i].first--, E[i].second--;

	mint ans=0;
	rep(S,1<<m) ans+=(popcount(S)%2==0?1:-1)*f(S);
	cout<<ans<<'\n';

	return 0;
}
