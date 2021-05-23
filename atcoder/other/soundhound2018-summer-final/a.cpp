#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b; scanf("%lld%lld",&a,&b);

	lint ans=0,x=140,y=170;
	while(x<1e16){
		ans+=max(min(y,b)-max(x,a),0LL);
		x*=2;
		y*=2;
	}
	printf("%lld\n",ans);

	return 0;
}
