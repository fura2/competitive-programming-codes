#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint a; scanf("%d%lld",&n,&a);
	if(getchar()==' ') return puts("\"assert\""),0;
	lint b,c; scanf("%lld%lld",&b,&c);
	printf("%lld\n",*----set<lint>{a+b,b+c,c+a}.end());
	return 0;
}
