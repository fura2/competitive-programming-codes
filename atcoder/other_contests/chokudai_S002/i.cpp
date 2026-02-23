#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld%lld",&a[i],&b[i]);

	int i0=0;
	for(int i=1;i<n;i++) if(a[i]*b[i]>a[i0]*b[i0]) i0=i;

	bool ok=true;
	rep(j,n) if(j!=i0 && (a[i0]+b[j]-1)/b[j]<=(a[j]+b[i0]-1)/b[i0]) ok=false;
	printf("%d\n",ok?i0+1:-1);

	return 0;
}
