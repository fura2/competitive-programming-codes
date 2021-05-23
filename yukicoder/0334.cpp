#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,a[12];
int ans[3];

bool dfs(int S){
	rep(i,n) if(S>>i&1) {
		for(int j=i+1;j<n;j++) if(S>>j&1 && a[i]!=a[j]) {
			for(int k=j+1;k<n;k++) if(S>>k&1 && a[k]!=a[i] && a[k]!=a[j]) {
				if(min({a[i],a[j],a[k]})==a[j] || max({a[i],a[j],a[k]})==a[j]){
					if(!dfs(S&~(1<<i)&~(1<<j)&~(1<<k))){
						ans[0]=i;
						ans[1]=j;
						ans[2]=k;
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	if(!dfs((1<<n)-1)) puts("-1");
	else printf("%d %d %d\n",ans[0],ans[1],ans[2]);

	return 0;
}
