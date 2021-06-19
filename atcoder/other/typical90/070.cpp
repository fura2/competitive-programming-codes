#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> x(n),y(n);
	rep(i,n) scanf("%lld%lld",&x[i],&y[i]);

	sort(x.begin(),x.end());
	sort(y.begin(),y.end());

	lint ans=0;
	rep(i,n) ans+=abs(x[i]-x[n/2])+abs(y[i]-y[n/2]);
	printf("%lld\n",ans);

	return 0;
}
