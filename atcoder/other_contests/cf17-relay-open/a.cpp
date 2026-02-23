#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,k; cin>>k>>a>>b;

	if(a>=k) return puts("1"),0;

	if(a<=b) return puts("-1"),0;

	printf("%lld\n",(k-a+(a-b)-1)/(a-b)*2+1);

	return 0;
}
