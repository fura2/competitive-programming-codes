#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

int MOD;
class mint{
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

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

graph T;
mint dp1[100000],dp2[100000];

void dfs1(int u,int p){
	dp1[u]=1;
	for(int v:T[u]) if(v!=p) {
		dfs1(v,u);
		dp1[u]*=dp1[v]+1;
	}
}

void dfs2(int u,int p){
	vector<mint> C;
	for(int v:T[u]) if(v!=p) C.emplace_back(dp1[v]+1);

	int k=C.size();
	vector<mint> rprod(k+1);
	rprod[k]=1;
	for(int i=k-1;i>=0;i--) rprod[i]=rprod[i+1]*C[i];

	mint lprod=1;
	int idx=0;
	for(int v:T[u]) if(v!=p) {
		dp2[v]=dp2[u]*lprod*rprod[idx+1]+1;
		dfs2(v,u);
		lprod*=C[idx];
		idx++;
	}
}

int main(){
	int n; scanf("%d%d",&n,&MOD);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	dp2[0]=1;
	dfs1(0,-1);
	dfs2(0,-1);

	rep(u,n) printf("%d\n",(dp1[u]*dp2[u]).to_int());

	return 0;
}
