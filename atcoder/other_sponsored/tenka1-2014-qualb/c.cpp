#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,B[750][750],res[750][750];

int f(int i,int j){
	int sum=B[i][j];
	if(i> 0 ) sum^=res[i-1][j];
	if(j> 0 ) sum^=res[i][j-1];
	if(i<n-1) sum^=res[i+1][j];
	if(j<n-1) sum^=res[i][j+1];
	return sum;
}

int main(){
	scanf("%d",&n);
	rep(i,n){
		char s[751]; scanf("%s",s);
		rep(j,n) B[i][j]=(s[j]=='#'?1:0);
	}

	rep(i,n-1) rep(j,n) res[i+1][j]=f(i,j);

	rep(i,n){
		rep(j,n) printf("%c",res[i][j]==1?'#':'.');
		puts("");
	}

	return 0;
}
