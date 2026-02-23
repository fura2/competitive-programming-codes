#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int h,w;
char B[10][11];

char ans[11];

void dfs(int t,int x){
	if(B[h-1-t][x]=='x') return;

	if(t==h-1){
		puts(ans);
		exit(0);
	}

	ans[t]='S';
	dfs(t+1,x);
	if(x>0){
		ans[t]='L';
		dfs(t+1,x-1);
	}
	if(x<w-1){
		ans[t]='R';
		dfs(t+1,x+1);
	}
}

int main(){
	scanf("%d%d",&h,&w);
	rep(i,h) scanf("%s",B[i]);

	int x;
	rep(j,w) if(B[h-1][j]=='s') x=j;

	dfs(0,x);
	puts("impossible");

	return 0;
}
