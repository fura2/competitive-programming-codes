#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,k; scanf("%lld%lld",&n,&k);
	printf("%lld\n",(n+k+1)/(k+1));
	return 0;
}
