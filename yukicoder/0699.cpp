#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[14];

int ans;

void dfs(int S,int val){
	if(S==(1<<n)-1){
		ans=max(ans,val);
		return;
	}

	int i;
	for(i=0;S>>i&1;i++);
	for(int j=i+1;j<n;j++) if((S>>j&1)==0) dfs(S|1<<i|1<<j,val^(a[i]+a[j]));
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	dfs(0,0);
	printf("%d\n",ans);

	return 0;
}
