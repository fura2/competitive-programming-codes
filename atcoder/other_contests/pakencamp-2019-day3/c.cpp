#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int a[100][100];
	rep(i,n) rep(j,m) scanf("%d",&a[i][j]);

	lint ans=0;
	rep(j,m) rep(k,j) {
		lint tmp=0;
		rep(i,n) tmp+=max(a[i][j],a[i][k]);
		ans=max(ans,tmp);
	}
	printf("%lld\n",ans);

	return 0;
}
