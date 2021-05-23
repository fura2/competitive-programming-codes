#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n;
lint v,a[20],sum[1<<20];

bool vis[1<<20],memo[1<<20];

bool dfs(int S){
	if(vis[S]) return memo[S];
	vis[S]=true;

	bool& res=memo[S];
	rep(i,n) if(~S>>i&1) {
		if(sum[S]+a[i]<=v && !dfs(S|1<<i)) return res=true;
	}
	return res=false;
}

int main(){
	scanf("%d%lld",&n,&v);
	rep(i,n) scanf("%lld",&a[i]);

	rep(S,1<<n) rep(i,n) if(S>>i&1) sum[S]+=a[i];
	if(sum[(1<<n)-1]<=v){
		puts("Draw");
		return 0;
	}

	puts(dfs(0)?"First":"Second");

	return 0;
}
