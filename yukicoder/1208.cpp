#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n;
lint m,a[200000];

lint dfs(int i){
	if(i==n) return 0;

	lint tmp=dfs(i+1);
	lint res=a[i]-m-tmp; // 全部取る
	if(a[i]>1){
		res=max(res,a[i]-1+m+tmp); // 1 個残す
	}
	return res;
}

int main(){
	scanf("%d%lld",&n,&m);
	rep(i,n) scanf("%lld",&a[i]);

	puts(dfs(0)>0?"First":"Second");

	return 0;
}
