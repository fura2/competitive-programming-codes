#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int fib[46]={1,1};
	for(int i=2;i<=n;i++) fib[i]=fib[i-1]+fib[i-2];
	printf("%d\n",fib[n]);

	return 0;
}
