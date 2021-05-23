#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int A[500][500];

void dfs(int l,int r,int id){
	int n=r-l;
	if(n<=1) return;
	// K_{n/2,(n+1)/2}
	for(int u=l;u<l+n/2;u++) for(int v=l+n/2;v<r;v++) A[u][v]=id;
	// K_{n/2} cup K_{(n+1)/2}
	dfs(l,l+n/2,id+1);
	dfs(l+n/2,r,id+1);
}

int main(){
	int n; scanf("%d",&n);
	dfs(0,n,1);
	rep(u,n-1) for(int v=u+1;v<n;v++) printf("%d%c",A[u][v],v<n-1?' ':'\n');
	return 0;
}
