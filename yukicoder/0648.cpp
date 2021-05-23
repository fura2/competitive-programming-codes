#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	lint m=(sqrt(1+8.0L*n)-1)/2+0.5;
	if(m*(m+1)/2==n) printf("YES\n%lld\n",m);
	else puts("NO");

	return 0;
}
