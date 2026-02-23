#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector A(n,vector<int>(n));
	rep(i,n) rep(j,n) scanf("%d",&A[i][j]);

	int m; scanf("%d",&m);
	vector bad(n,vector<bool>(n));
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		bad[u][v]=bad[v][u]=true;
	}

	int ans=INF;
	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	do{
		bool ok=true;
		int cost=0;
		rep(i,n){
			int u=p[i];
			if(i<n-1){
				int v=p[i+1];
				if(bad[u][v]){
					ok=false;
					break;
				}
			}
			cost+=A[u][i];
		}
		if(ok) ans=min(ans,cost);
	}while(next_permutation(p.begin(),p.end()));

	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
