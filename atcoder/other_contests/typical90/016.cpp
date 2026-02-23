#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,a,b,c;
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);

	int ans=10000;
	rep(i,10001){
		if(i*a>n) break;
		rep(j,10001-i){
			if(i*a+j*b>n) break;
			if((n-(i*a+j*b))%c==0){
				int k=(n-(i*a+j*b))/c;
				ans=min(ans,i+j+k);
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
