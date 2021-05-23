#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	bool A[50][50]={};
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v);
		A[u][v]=A[v][u]=true;
	}

	int ans=0;
	rep(i,n){
		rep(j,n) if(j!=i && A[i][j]) {
			rep(k,n) if(k!=i && k!=j && A[j][k] && !A[i][k]) {
				rep(l,n) if(l!=i && l!=j && l!=k && A[k][l] && A[l][i] && !A[j][l]) {
					ans++;
				}
			}
		}
	}
	printf("%d\n",ans/8);

	return 0;
}
