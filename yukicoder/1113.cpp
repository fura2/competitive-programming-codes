#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b; cin>>a>>b;

	lint g=gcd(a,b);
	lint x=sqrt(g);
	rep(i,2) if((x+i)*(x+i)==g) return puts("Odd"),0;
	puts("Even");

	return 0;
}
