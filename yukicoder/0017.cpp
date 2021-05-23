#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m,c[50]; scanf("%d",&n);
	rep(u,n) scanf("%d",&c[u]);
	scanf("%d",&m);

	int d[50][50];
	rep(u,n) rep(v,n) d[u][v]=(u==v?0:INF);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		d[u][v]=d[v][u]=c;
	}

	rep(k,n) rep(i,n) rep(j,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

	int ans=INF;
	rep(u,n-1) rep(v,n-1) if(u!=0 && v!=0 && u!=v) {
		ans=min(ans,d[0][u]+d[u][v]+d[v][n-1]+c[u]+c[v]);
	}
	printf("%d\n",ans);

	return 0;
}
