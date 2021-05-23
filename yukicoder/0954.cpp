#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint fib[100]={1,1};
	rep(i,90) fib[i+2]=fib[i+1]+fib[i];

	lint a[5];
	rep(i,5) scanf("%lld",&a[4-i]);

	for(int d=5;d>0;d--){
		bool found=false;
		rep(i,90-d){
			bool ok=true;
			rep(j,d) if(a[j]!=fib[i+j]) ok=false;
			if(ok) found=true;
		}
		if(found) return printf("%d\n",d),0;
	}
	puts("0");

	return 0;
}
