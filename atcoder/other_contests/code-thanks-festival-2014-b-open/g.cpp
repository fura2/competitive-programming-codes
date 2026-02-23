#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int memo[501][501];

int dfs(int n,int p){
	int& res=memo[n][p];
	if(res!=-1) return res;
	if(n==0) return res=0;
	for(int i=1;i<=min(p,n);i++) if(!dfs(n-i,i+1)) return res=1;
	return res=0;
}

int main(){
	int n,p; scanf("%d%d",&n,&p);
	memset(memo,-1,sizeof memo);
	puts(dfs(n,p)==1?"first":"second");
	return 0;
}
