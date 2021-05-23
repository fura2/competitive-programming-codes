#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	lint lo=-1,hi=1e18+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		lint x=mi+1;
		rep(i,n-1){
			x-=(x+k-1)/k;
		}
		if(x>0) hi=mi;
		else    lo=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
