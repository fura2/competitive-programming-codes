#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; scanf("%lld%lld",&n,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	printf("%lld\n",accumulate(a.begin(),a.begin()+k,0LL)+k*(k-1)/2);

	return 0;
}
