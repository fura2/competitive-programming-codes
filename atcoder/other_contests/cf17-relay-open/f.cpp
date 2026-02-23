#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> x(n),a(n);
	rep(i,n) scanf("%lld%lld",&x[i],&a[i]);

	lint ans=a[n-1],mx=a[n-1];
	for(int i=n-1;i>0;i--){
		mx=max(mx+a[i-1]-(x[i]-x[i-1]),a[i-1]);
		ans=max(ans,mx);
	}
	printf("%lld\n",ans);

	return 0;
}
