#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	lint k=(lint(sqrt(1.0L+8*n)+0.5)-1)/2;
	printf("%lld\n",k*(k+1)==2*n?k:-1);

	return 0;
}
