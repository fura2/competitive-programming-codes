#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint f(lint x){ return (x*x+4)/8; }

int main(){
	lint x=20;
	x=f(x);
	x=f(x);
	x=f(x);
	printf("%lld\n",x);
	return 0;
}
