#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	lint ans=0;
	rep(i,n) ans+=abs(a[i]-b[i]);
	printf("%lld\n",ans);

	return 0;
}
