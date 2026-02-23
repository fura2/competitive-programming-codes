#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c; cin>>a>>b>>c;
	lint g=gcd(gcd(a,b),c);
	printf("%lld\n",a/g+b/g+c/g-3);
	return 0;
}
