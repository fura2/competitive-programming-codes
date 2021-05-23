#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,q; scanf("%d%d",&n,&q);

	vector d(n,vector(n,INF));
	rep(u,n) d[u][u]=0;
	rep(_,q){
		int type,u,v; scanf("%d%d%d",&type,&u,&v); u--; v--;
		if(type==0){
			printf("%d\n",d[u][v]<INF?d[u][v]:-1);
		}
		else{
			int c; scanf("%d",&c);
			rep(i,n) rep(j,n) {
				d[i][j]=min(d[i][j],d[i][u]+c+d[v][j]);
				d[i][j]=min(d[i][j],d[i][v]+c+d[u][j]);
			}
		}
	}

	return 0;
}
