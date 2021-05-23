#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int m[3],n; scanf("%d%d%d%d",&m[0],&m[1],&m[2],&n);
	int a[1000][3],b[1000];
	rep(i,n){
		rep(j,3) scanf("%d",&a[i][j]), a[i][j]--;
		a[i][1]-=m[0];
		a[i][2]-=m[0]+m[1];
		scanf("%d",&b[i]);
	}

	bool ok[3][100]={},ng[3][100]={};
	rep(i,n) if(b[i]==1) rep(j,3) ok[j][a[i][j]]=true;
	rep(i,n) if(b[i]==0) {
		if(ok[0][a[i][0]] && ok[1][a[i][1]])  ng[2][a[i][2]]=true;
		if(ok[1][a[i][1]] && ok[2][a[i][2]])  ng[0][a[i][0]]=true;
		if(ok[2][a[i][2]] && ok[0][a[i][0]])  ng[1][a[i][1]]=true;
	}

	rep(j,3) rep(i,m[j]) printf("%d\n",ng[j][i]?0:ok[j][i]?1:2);

	return 0;
}
