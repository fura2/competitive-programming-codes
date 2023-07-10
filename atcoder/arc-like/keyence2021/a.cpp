#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	vector<lint> c(n);
	c[0]=a[0]*b[0];
	lint a_max=a[0];
	for(int i=1;i<n;i++){
		a_max=max(a_max,a[i]);
		c[i]=max(c[i-1],a_max*b[i]);
	}

	rep(i,n) printf("%lld\n",c[i]);

	return 0;
}
