#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int m; scanf("%d",&m);

	lint ans=m-1,sum=0;
	rep(i,m){
		int d;
		lint c; scanf("%d%lld",&d,&c);
		ans+=c-1;
		sum+=c*d;
	}
	ans+=sum/9;
	if(sum%9==0) ans--;

	printf("%lld\n",ans);

	return 0;
}
