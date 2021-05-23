#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint b; scanf("%lld",&b);
	int n; scanf("%d",&n);
	vector<lint> c(n);
	rep(i,n) scanf("%lld",&c[i]);

	lint ub=(b+accumulate(c.begin(),c.end(),0LL))/n;

	sort(c.begin(),c.end());
	lint med=c[n/2];

	lint ans=0;
	rep(i,n) ans+=abs(c[i]-min(ub,med));
	printf("%lld\n",ans);

	return 0;
}
