#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n,m; scanf("%d%d",&n,&m);
	vector d(n,vector(n,false));
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		d[u][v]=d[v][u]=true;
	}
//rep(u,n){ rep(v,n) printf("%d ",!!d[u][v]); puts(""); }

	auto dfs=[&](auto&& dfs,int turn)->bool{
		auto D=d;
		rep(k,n) rep(i,n) rep(j,n) D[i][j]=D[i][j]||(D[i][k]&&D[k][j]);
		if(D[0][n-1]) return true;

		rep(i,n) for(int j=i+1;j<n;j++) if(!d[i][j]) {
			d[i][j]=d[j][i]=true;
//printf("turn = %d: i = %d, j = %d\n",turn,i+1,j+1);
			bool b=dfs(dfs,1-turn);
			d[i][j]=d[j][i]=false;
			if(!b) return true;
		}
		return false;
	};

	puts(dfs(dfs,0)?"First":"Second");
}

int main(){
//puts(dfs(0,0,0,{1,1,1,1,1,1})?"First":"Second"); return 0;
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
