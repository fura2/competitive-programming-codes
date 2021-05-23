#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	bool A[100][100]={};
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		A[u][v]=A[v][u]=true;
	}

	bool B[100][100]={};
	rep(u,n) rep(v,n) {
		B[u][v]=true;
		rep(w,n) if(A[u][w] && A[w][v]) B[u][v]=false;
		if(A[u][v]) B[u][v]=true;
	}

	int ans=0;
	rep(u,n) for(int v=u+1;v<n;v++) for(int w=v+1;w<n;w++) if(B[u][v] && B[u][w] && B[v][w]) ans++;
	printf("%d\n",ans);

	return 0;
}
