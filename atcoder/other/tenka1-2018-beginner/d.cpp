#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int m;
	for(m=1;m*(m-1)/2<n;m++);
	if(m*(m-1)/2!=n) return puts("No"),0;

	vector<vector<int>> A(m,vector<int>(m));
	int e=0;
	rep(u,m) for(int v=u+1;v<m;v++) {
		A[u][v]=A[v][u]=e;
		e++;
	}

	printf("Yes\n%d\n",m);
	rep(u,m){
		printf("%d",m-1);
		rep(v,m) if(v!=u) printf(" %d",A[u][v]+1);
		puts("");
	}

	return 0;
}
