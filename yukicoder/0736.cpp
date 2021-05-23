#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);
	lint g=0;
	rep(i,n) g=gcd(g,a[i]);
	rep(i,n) printf("%lld%c",a[i]/g,i<n-1?':':'\n');
	return 0;
}
