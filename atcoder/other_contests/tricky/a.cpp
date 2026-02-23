#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	lint a,b; scanf("%lld%lld",&a,&b);
	if(a==LLONG_MIN && b==-1) puts("9223372036854775808");
	else printf("%lld\n",a/b);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
