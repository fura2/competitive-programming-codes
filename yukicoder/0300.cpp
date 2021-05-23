#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x; scanf("%lld",&x);
	for(lint a=2;a*a<=x;a++) if(x%(a*a)==0) x/=a*a, a--;
	printf("%lld\n",x);
	return 0;
}
