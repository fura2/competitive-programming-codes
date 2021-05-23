#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint m; scanf("%lld",&m);
	for(lint i=2;i*i<=m;i++) if(m%i==0) return printf("%lld %lld\n",i,m/i),0;
	printf("1 %lld\n",m);
	return 0;
}
