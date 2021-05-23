#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,a[50][50]; scanf("%d%d",&n,&m);
	rep(i,n) rep(j,n) scanf("%d",&a[i][j]);

	rep(i,n) rep(j,n) printf("2 %d %d\n",i,j);

	return 0;
}
