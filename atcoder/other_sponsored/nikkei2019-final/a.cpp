#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	vector<lint> ans(n+1);
	rep(l,n) for(int r=l+1;r<=n;r++) ans[r-l]=max(ans[r-l],cum[r]-cum[l]);
	rep(i,n) printf("%lld\n",ans[i+1]);

	return 0;
}
