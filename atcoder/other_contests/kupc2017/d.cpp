#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

// experiment
/*
int n,B[16][16];

int dfs(int i,int j){
	if(i==n) return 1;
	if(j==n) return dfs(i+1,0);

	int res=0;
	rep(d,2){
		B[i][j]=d;
		bool ok=true;
		if(i>=2 && B[i][j]==B[i-1][j] && B[i][j]==B[i-2][j]) ok=false;
		if(j>=2 && B[i][j]==B[i][j-1] && B[i][j]==B[i][j-2]) ok=false;
		if(i>=2 && j>=2 && B[i][j]==B[i-1][j-1] && B[i][j]==B[i-2][j-2]) ok=false;
		if(i>=2 && j<n-2 && B[i][j]==B[i-1][j+1] && B[i][j]==B[i-2][j+2]) ok=false;
		if(ok) res+=dfs(i,j+1);
	}
	return res;
}
*/

int main(){
	int ans[]={0,0,0,32,18,8};

	int n; scanf("%d",&n);
	if(n<=2){
		puts("1 1");
	}
	else{
		printf("2 %d\n",ans[min(n,5)]);
	}

	return 0;
}
