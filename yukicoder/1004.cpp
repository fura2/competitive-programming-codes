#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x0,n; scanf("%*lld%*lld%lld%lld",&x0,&n);
	if(x0%2==0) printf("0 %lld\n",n/2);
	else        printf("%lld 0\n",n/2);
	return 0;
}
