#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	char B1[500][501],B2[500][501],tmp[500][501];
	rep(i,n) scanf("%s",B1[i]);
	rep(i,n) scanf("%s",B2[i]);

	int res[4]={0,1,2,1};
	rep(k,4){
		rep(i,n) rep(j,n) if(B1[i][j]!=B2[i][j]) res[k]++;

		rep(i,n) rep(j,n) tmp[i][j]=B1[i][j];
		rep(i,n) rep(j,n) B1[j][n-i-1]=tmp[i][j];
	}
	printf("%d\n",*min_element(res,res+4));

	return 0;
}
