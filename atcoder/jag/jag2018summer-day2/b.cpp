#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	int ans=0;
	rep(a,5) rep(b,2) rep(c,5) rep(d,2) rep(e,5) {
		if(a+b+c+d+e<=n) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
