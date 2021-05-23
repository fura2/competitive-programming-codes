#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint fib[51]={1,1};
	int n; scanf("%d",&n);
	for(int i=2;i<=n;i++) fib[i]=fib[i-1]+fib[i-2];
	printf("%lld\n",fib[n]);
	return 0;
}
