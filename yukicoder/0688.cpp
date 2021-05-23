#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint k; scanf("%lld",&k);

	for(lint n=1;n<=30;n++) for(lint m=0;m<=30;m++) if(n+m<=30 && n*(n-1)/2*(1<<m)==k) {
		printf("%lld\n",n+m);
		rep(i,n+m) printf("%d%c",i<n?1:0,i<n+m-1?' ':'\n');
		return 0;
	}

	return 0;
}
