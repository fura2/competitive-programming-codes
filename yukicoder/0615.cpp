#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	vector<lint> d(n-1);
	rep(i,n-1) d[i]=a[i+1]-a[i];
	sort(d.begin(),d.end());

	printf("%lld\n",accumulate(d.begin(),d.end()-k+1,0LL));

	return 0;
}
