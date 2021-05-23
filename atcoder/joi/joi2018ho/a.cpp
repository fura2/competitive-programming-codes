#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> d(n-1);
	rep(i,n-1) d[i]=a[i+1]-a[i]-1;
	sort(d.rbegin(),d.rend());

	lint ans=a[n-1]-a[0]+1;
	rep(i,k-1) ans-=d[i];
	printf("%lld\n",ans);

	return 0;
}
