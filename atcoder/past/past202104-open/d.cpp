#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	rep(i,n-k+1) printf("%lld\n",cum[i+k]-cum[i]);

	return 0;
}
