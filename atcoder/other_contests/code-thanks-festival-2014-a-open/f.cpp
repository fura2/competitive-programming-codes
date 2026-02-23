#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	bool A[50][50]={};
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		A[u][v]=true;
	}

	rep(k,n) rep(i,n) rep(j,n) A[i][j]|=A[i][k]&A[k][j];

	int cnt=1;
	rep(u,n) if(A[u][0]) cnt++;
	printf("%d\n",cnt);

	return 0;
}
