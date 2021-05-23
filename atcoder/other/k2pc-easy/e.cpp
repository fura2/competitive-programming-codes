#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	if(n==2) return puts("0"),0;

	lint m=sqrt(n)+0.5;
	if(m*m!=n) return puts("-1"),0;

	lint ans=n-2;
	for(;m>1;m--){
		ans+=1+(m>2?(m-1)*(m-1)-m:0);
	}
	printf("%lld\n",ans);

	return 0;
}
