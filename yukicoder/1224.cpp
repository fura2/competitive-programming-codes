#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b; scanf("%lld%lld",&a,&b);

	b/=gcd(a,b);
	while(b%2==0) b/=2;
	while(b%5==0) b/=5;
	puts(b>1?"Yes":"No");

	return 0;
}
