#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint fib[70]={0,1};
	for(int i=2;i<70;i++) fib[i]=fib[i-1]+fib[i-2];

	lint n; scanf("%lld",&n);

	int ans=0;
	for(int i=69;i>0;i--){
		if(fib[i]<=n){
			ans++;
			n-=fib[i];
		}
	}
	printf("%d\n",ans);

	return 0;
}
