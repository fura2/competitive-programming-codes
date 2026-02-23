#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int n,a[3000];
lint memo[3001][3001];

lint dfs(int l,int r){
	if(l==r) return 0;
	if(memo[l][r]>-INF) return memo[l][r];
	return memo[l][r]=max(a[l]-dfs(l+1,r),a[r-1]-dfs(l,r-1));
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	rep(l,n+1) rep(r,n+1) memo[l][r]=-INF;

	printf("%lld\n",dfs(0,n));

	return 0;
}
