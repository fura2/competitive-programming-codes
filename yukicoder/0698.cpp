#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[14];

int dfs(int S){
	if(S==(1<<n)-1) return 0;

	int res=0,i;
	for(i=0;S>>i&1;i++);
	for(int j=i+1;j<n;j++) if((S>>j&1)==0) res=max(res,dfs(S|1<<i|1<<j)+(a[i]^a[j]));
	return res;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	printf("%d\n",dfs(0));
	return 0;
}
