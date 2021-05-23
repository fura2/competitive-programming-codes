#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m;
	lint c; scanf("%d%d%lld",&n,&m,&c);
	vector<lint> a(n),b(m);
	rep(i,n) scanf("%lld",&a[i]);
	rep(j,m) scanf("%lld",&b[j]);

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	lint res=0;
	rep(i,n){
		res+=b.end()-lower_bound(b.begin(),b.end(),c/a[i]+1);
	}
	printf("%.9f\n",double(res)/n/m);

	return 0;
}
