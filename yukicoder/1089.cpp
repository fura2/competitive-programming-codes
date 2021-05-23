#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans=0;
	rep(x,n+1) rep(y,n+1) if(n-x-y>=0) ans++;
	printf("%d\n",ans);

	return 0;
}
