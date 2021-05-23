#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[1<<17],inv[1<<16];
int ans[1<<16];

void dfs(int x,int dep){
	if(x<(1<<n)){
		rep(j,2){
			dfs(2*x+j,dep+1);
			ans[inv[a[2*x+j]]]=max(ans[inv[a[2*x+j]]],n-dep);
		}
		a[x]=max(a[2*x],a[2*x+1]);
	}
}

int main(){
	scanf("%d",&n);
	rep(i,1<<n){
		int x; scanf("%d",&x);
		a[i+(1<<n)]=x;
		inv[x]=i;
	}

	dfs(1,0);

	rep(i,1<<n) printf("%d\n",ans[i]);

	return 0;
}
