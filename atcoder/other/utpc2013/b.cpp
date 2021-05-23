#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint y,m; scanf("%lld%lld",&y,&m);

	lint x=(y-2013)*12+(m-1);

	lint lo=0,hi=2e9;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		if((25+mi)*mi/2<=x) lo=mi;
		else                hi=mi;
	}
	printf("%lld %lld\n",lo+2013,x-(25+lo)*lo/2+1);

	return 0;
}
