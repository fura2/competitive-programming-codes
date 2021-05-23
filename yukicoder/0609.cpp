#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	lint ans=0;
	rep(i,n) ans+=abs(a[i]-a[n/2]);
	printf("%lld\n",ans);

	return 0;
}
