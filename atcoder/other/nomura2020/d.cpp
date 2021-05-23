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

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

vector<vector<int>> connected_components(const graph& G){
	int n=G.size();
	vector<vector<int>> res;
	vector<bool> vis(n);
	rep(u,n) if(!vis[u]) {
		vis[u]=true;
		res.emplace_back();
		queue<int> Q; Q.emplace(u);
		while(!Q.empty()){
			int v=Q.front(); Q.pop();
			res.back().emplace_back(v);
			for(int w:G[v]) if(!vis[w]) {
				vis[w]=true;
				Q.emplace(w);
			}
		}
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	graph G(n);
	vector<bool> to(n);
	rep(u,n){
		int v; scanf("%d",&v); v--;
		if(v<0) to[u]=true;
		else    add_undirected_edge(G,u,v);
	}

	int namori=0;
	vector<int> a; // 木の頂点数のリスト
	for(auto C:connected_components(G)){
		bool b=true;
		for(int u:C) if(to[u]) b=false;
		if(b) namori++;
		else  a.emplace_back(C.size());
	}
	int k=a.size();

	vector<mint> dp(k+1);
	dp[0]=1;
	rep(i,k) for(int j=k;j>0;j--) dp[j]+=a[i]*dp[j-1];

	mint ans=pow(mint(n-1),k)*(n-namori);
	for(int i=1;i<=k;i++){
		mint c=dp[i]; // i 個の木を使ってできるサイクルの総数
		if(i==1) c-=k;
		ans-=c*fact(i-1)*pow(mint(n-1),k-i);
	}
	cout<<ans<<'\n';

	return 0;
}
