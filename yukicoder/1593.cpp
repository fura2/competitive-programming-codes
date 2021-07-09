#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; scanf("%lld",&n);

	int ans=0;
	for(lint x=1;x<n;x++){
		lint y=sqrt(n*n-x*x);
		if(x*x+y*y==n*n) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
