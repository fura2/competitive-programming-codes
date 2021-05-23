#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int n;
lint a[400];

lint memo[401][401][401];

lint dfs(int l,int r,int k){
	lint& res=memo[l][r][k];
	if(res!=-1) return res;

	if(l==0 && r==n){
		if     (n%2==0 && k==1) res=0;
		else if(n%2==1 && k==0) res=0;
		else res=INF;
		return res;
	}

	res=INF;
	if(k>0){
		if(l>0) res=min(res,dfs(l-1,r,k-1));
		if(r<n) res=min(res,dfs(l,r+1,k-1));
	}
	// 蟻が左に移動
	if(l>0 && (r==n || a[l-1]>a[r])){
		res=min(res,dfs(l-1,r,k+1)+a[l-1]);
	}
	// 蟻が右に移動
	else if(r<n && (l==0 || a[l-1]<a[r])){
		res=min(res,dfs(l,r+1,k+1)+a[r]);
	}
	else abort();

	return res;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%lld",&a[i]);

	lint total=accumulate(a,a+n,0LL);
	memset(memo,-1,sizeof memo);
	rep(i,n+1) printf("%lld\n",total-dfs(i,i,1));

	return 0;
}
