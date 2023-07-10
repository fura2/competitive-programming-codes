#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	vector<int> sum(n);
	rep(i,n) sum[i]=a[i]+b[i];

	sort(sum.rbegin(),sum.rend());

	lint ans=0;
	rep(i,n) ans+=a[i];
	for(int i=1;i<n;i+=2) ans-=sum[i];
	printf("%lld\n",ans);

	return 0;
}
