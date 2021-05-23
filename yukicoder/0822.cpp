#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	if(n<=k-1) return puts("INF"),0;

	int ans=0;
	rep(x,1e6) for(int y=x;y<=x+k;y++) if((x&y)==n) ans++;
	printf("%d\n",ans);

	return 0;
}
