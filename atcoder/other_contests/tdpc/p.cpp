#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint &operator+=(const mint &m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint &operator-=(const mint &m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint &operator*=(const mint &m){ x=1LL*x*m.x%MOD; return *this; }
	mint operator+(const mint &m)const{ return mint(*this)+=m; }
	mint operator-(const mint &m)const{ return mint(*this)-=m; }
	mint operator*(const mint &m)const{ return mint(*this)*=m; }

	friend ostream &operator<<(ostream &os,const mint &m){ return os<<m.x; }
};

int n;
vector<int> T[1000];

vector<bool> vis[1000][51][3];
vector<mint> memo[1000][51][3];

// i : index of children of u (child-sibling representation)
// type == 0 : u をまだ使っていない
//         1 : これまで見た頂点のどれかが u とつながっていて, u の次をまだ決めていない
//         2 : これまで見た頂点のどれかが u とつながっていて, u の次をもう決めた
mint dfs(int u,int p,int i,int k,int type){
	if(k==0) return type==1?0:1;
	if(i==T[u].size()) return (k==1&&type==1)?1:0;

	int v=T[u][i];
	if(v==p) return dfs(u,p,i+1,k,type);

	if(vis[u][k][type][i]) return memo[u][k][type][i];
	vis[u][k][type][i]=true;

	mint res=0;
	if(type==0){
		rep(j,k+1) res+=dfs(v,u,0,j,0)*dfs(u,p,i+1,k-j,0); // don't use u-v
		rep(j,k) res+=dfs(v,u,0,j+1,1)*dfs(u,p,i+1,k-j,1); // use u-v
	}
	else if(type==1){
		rep(j,k+1) res+=dfs(v,u,0,j,0)*dfs(u,p,i+1,k-j,1); // use *-u, don't use u-v
		rep(j,k+1) res+=dfs(v,u,0,j,1)*dfs(u,p,i+1,k-j,2); // use *-u-v
	}
	else{ // type==2
		rep(j,k+1) res+=dfs(v,u,0,j,0)*dfs(u,p,i+1,k-j,2); // don't use u-v
	}
	return memo[u][k][type][i]=res;
}

int main(){
	int k; cin>>n>>k;
	rep(i,n-1){
		int u,v; cin>>u>>v; u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	int root;
	rep(u,n) if(T[u].size()==1) root=u;

	rep(u,n) rep(j,k+1) rep(type,3) {
		vis[u][j][type].assign(T[u].size(),false);
		memo[u][j][type].assign(T[u].size(),0);
	}

	cout<<dfs(root,-1,0,k,0)<<endl;

	return 0;
}
