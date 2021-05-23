/*
	未使用の人のうち一番番号が小さい人を次に使うことにすると, 探索する空間が小さくなって計算量が落ちる
	O(n*1.619^n)
	https://twitter.com/kyopro_friends/status/1338127703841464320
*/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,A[24][24];

int memo[1<<24];

int dfs(int S){
	int& res=memo[S];
	if(res!=-1) return res;

	if(S==(1<<n)-1) return res=0;

	int i;
	for(i=0;S>>i&1;i++);

	res=0;
	for(int j=i+1;j<n;j++) if(~S>>j&1) {
		res=max(res,dfs(S|1<<i|1<<j)+A[i][j]);
	}
	return res;
}

int main(){
	scanf("%d",&n);
	rep(i,n) rep(j,n) scanf("%d",&A[i][j]);

	memset(memo,-1,sizeof memo);
	printf("%d\n",dfs(0));

	return 0;
}
