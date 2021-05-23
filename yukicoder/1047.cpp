#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b; scanf("%lld%lld",&a,&b);
	if     (b==0)     puts("1");
	else if(a*b+b==0) puts("2");
	else              puts("-1");
	return 0;
}
