#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n,a[4000];

lint memo[4000][4000];

lint dfs(int l,int r){
	if(l==r) return 0;
	if(l+1==r) return a[l];

	if(memo[l][r]!=-1) return memo[l][r];

	lint res=0;
	if(a[l+1]>a[r-1]) res=max(res,a[l]+dfs(l+2,r));
	else              res=max(res,a[l]+dfs(l+1,r-1));
	if(a[l]>a[r-2]) res=max(res,a[r-1]+dfs(l+1,r-1));
	else            res=max(res,a[r-1]+dfs(l,r-2));
	return memo[l][r]=res;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]), a[n+i]=a[i];

	memset(memo,-1,sizeof memo);

	lint ans=0;
	rep(i,n) ans=max(ans,dfs(i,n+i));
	printf("%lld\n",ans);

	return 0;
}
