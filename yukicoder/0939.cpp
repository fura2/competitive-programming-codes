#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b; cin>>a>>b;

	if((a&b)!=a) return puts("0"),0;
	if(a==b) return puts("1"),0;

	lint ans=1;
	rep(i,32) if((a>>i&1)==0 && (b>>i&1)!=0) ans*=2;
	printf("%lld\n",ans/2);

	return 0;
}
