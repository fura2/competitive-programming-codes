#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }
template<class T> T lcm(const T& a,const T& b){ return a/gcd(a,b)*b; }

int main(){
	lint n,a,b,c; scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	printf("%lld\n",n/a+n/b+n/c-n/lcm(a,b)-n/lcm(b,c)-n/lcm(c,a)+n/lcm(lcm(a,b),c));
	return 0;
}
