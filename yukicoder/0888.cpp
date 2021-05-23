#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);
	lint ans=0;
	for(lint i=1;i*i<=n;i++) if(n%i==0) {
		ans+=i;
		if(i*i<n) ans+=n/i;
	}
	printf("%lld\n",ans);
	return 0;
}
