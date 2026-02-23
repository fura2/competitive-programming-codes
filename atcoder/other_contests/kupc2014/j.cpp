#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int m,p,a[21];
int memo[101][101];

int dfs(int k,int n){ // 残り k 日で n 個買うときの残金の最大値
	int& res=memo[k][n];
	if(res!=-1) return res;

	if(k==0){
		return res=(n==0?0:-2);
	}

	res=-2;
	rep(i,min(n,m)+1){ // n 日目に i 個買う
		if(dfs(k-1,n-i)!=-2 && a[i]<=dfs(k-1,n-i)+p){
			res=max(res,dfs(k-1,n-i)+p-a[i]);
		}
	}
	return res;
}

int main(){
	int n; scanf("%d%d%d",&n,&m,&p);
	rep(i,m) scanf("%d",&a[i+1]);

	rep(i,m) a[i+1]+=a[i];
	memset(memo,-1,sizeof memo);

	int i;
	for(i=0;dfs(i,n)==-2;i++);
	printf("%d\n",i);

	return 0;
}
