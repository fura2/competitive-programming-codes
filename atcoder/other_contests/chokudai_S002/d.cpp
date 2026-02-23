#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	lint ans=0;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		ans+=max(a,b);
	}
	printf("%lld\n",ans);
	return 0;
}
