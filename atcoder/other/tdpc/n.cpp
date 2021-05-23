#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=1e9+7;

lint xgcd(lint a,lint b,lint &x,lint &y){
	if(b==0){ x=1; y=0; return a; }
	lint g=xgcd(b,a%b,y,x); y-=a/b*x;
	return g;
}

lint modinv(lint a,lint m){
	lint x,y;
	if(xgcd(a,m,x,y)==1) return (x+m)%m;
	return -1;
}

lint fact[2001],finv[2001];

lint multi(const vector<int> &a){
	lint res=1;
	int m=0;
	for(int x:a) m+=x, res=res*finv[x]%MOD;
	return res*fact[m]%MOD;
}

int n;
vector<int> T[1000];

lint sz[1000][1000]; // sz[u][p] : number of edges in the subtree with root u

int dfs1(int u,int p){
	if(~sz[u][p]) return sz[u][p];
	int res=0;
	for(int v:T[u]) if(v!=p) res+=dfs1(v,u)+1;
	return sz[u][p]=res;
}

lint dfs2(int u,int p){
	lint res=1;
	vector<int> a;
	for(int v:T[u]) if(v!=p) {
		res=res*dfs2(v,u)%MOD;
		a.emplace_back(dfs1(v,u)+1);
	}
	return res*multi(a)%MOD;
}

int main(){
	cin>>n;
	rep(i,n-1){
		int u,v; cin>>u>>v; u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	fact[0]=finv[0]=1;
	rep(i,2*n){
		fact[i+1]=fact[i]*(i+1)%MOD;
		finv[i+1]=modinv(fact[i+1],MOD);
	}

	memset(sz,-1,sizeof sz);

	lint ans=0;
	rep(u,n) for(int v:T[u]) if(u<v) {
		ans=(ans+dfs2(u,v)*dfs2(v,u)%MOD*multi({dfs1(u,v),dfs1(v,u)}))%MOD;
	}
	cout<<ans<<endl;

	return 0;
}
