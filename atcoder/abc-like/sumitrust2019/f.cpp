#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint t1,t2,a1,a2,b1,b2;
	scanf("%lld%lld%lld%lld%lld%lld",&t1,&t2,&a1,&a2,&b1,&b2);

	if(a1<b1){
		swap(a1,b1);
		swap(a2,b2);
	}

	lint d=(a1-b1)*t1+(a2-b2)*t2;
	if     (d> 0) return puts("0"),0;
	else if(d==0) return puts("infinity"),0;

	d=-d;
	lint ans;
	if((a1-b1)*t1%d==0) ans=2*(((a1-b1)*t1)/d);
	else                ans=2*(((a1-b1)*t1)/d+1)-1;
	printf("%lld\n",ans);

	return 0;
}
