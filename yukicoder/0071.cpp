#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);
	printf("%lld\n",(n/2+1)*((n+1)/2+1)-1);
	return 0;
}
