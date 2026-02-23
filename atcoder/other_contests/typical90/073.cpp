#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

class mint{
	static const int MOD=1e9+7;
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

int n;
graph T;
int color[100000];

bool vis[100000][4][4];
mint memo[100000][4][4];

// 頂点 u の親からの色の寄与が S_par のとき,
// 頂点 u を含む連結成分に含まれる色の集合が S_tar で
// 他のすべての連結成分は 2 色を含むような辺の切り方の数
mint dfs(int u,int p,int S_par,int S_tar){
	mint& res=memo[u][S_par][S_tar];
	if(vis[u][S_par][S_tar]) return res;
	vis[u][S_par][S_tar]=true;

	int S0=S_par|(1<<color[u]);

	// dp[S] = ( 頂点 u を含む連結成分に含まれる色の集合が S で
	//           他のすべての連結成分は 2 色を含むような辺の切り方の数 )
	mint dp[4]={};
	dp[S0]=1;
	for(int v:T[u]) if(v!=p) {
		mint next[4]={};

		// 辺 (u,v) を切る
		rep(S,4) next[S]+=dp[S]*dfs(v,u,0,3);
		// 辺 (u,v) を残す
		rep(S,4) rep(S2,4) {
			next[S2]+=dp[S]*dfs(v,u,S,S2);
		}

		rep(S,4) dp[S]=next[S];
	}
	res=dp[S_tar];

	return res;
}

int main(){
	scanf("%d",&n);
	rep(u,n){
		char c; scanf(" %c",&c);
		color[u]=c-'a';
	}
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	cout<<dfs(0,-1,0,3)<<'\n';

	return 0;
}
