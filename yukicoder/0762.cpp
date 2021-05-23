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

mint operator+(long long y,const mint& m){ return m+y; }
mint operator*(long long y,const mint& m){ return m*y; }

using graph=vector<vector<int>>;

void add_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n,m;
	string s; cin>>n>>m>>s;
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_edge(G,u,v);
	}

	vector<mint> dp(n);
	rep(u,n) if(s[u]=='P') dp[u]=1;
	rep(u,n) if(s[u]=='P') for(int v:G[u]) if(s[v]=='D') dp[v]+=dp[u];
	rep(u,n) if(s[u]=='D') for(int v:G[u]) if(s[v]=='C') dp[v]+=dp[u];
	rep(u,n) if(s[u]=='C') for(int v:G[u]) if(s[v]=='A') dp[v]+=dp[u];

	mint ans=0;
	rep(u,n) if(s[u]=='A') ans+=dp[u];
	cout<<ans<<'\n';

	return 0;
}
