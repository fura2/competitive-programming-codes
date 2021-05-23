#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int a[500][500],b[500][500];
	rep(i,n) rep(j,m) scanf("%d",&a[i][j]);
	rep(i,n) rep(j,m) scanf("%d",&b[i][j]);

	int t=0;
	rep(i,n){
		int t2=INF;
		rep(j,m) t2=min(t2,(t+a[i][j]-1)/a[i][j]*a[i][j]+b[i][j]);
		t=t2;
	}
	printf("%d\n",t);

	return 0;
}
