#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);
	lint ans=2*n;
	for(;n>0;n/=2) ans-=n;
	printf("%lld\n",ans);
	return 0;
}
