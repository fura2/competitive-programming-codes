#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint d; scanf("%lld",&d);

	auto dist=[](lint x,int n){
		lint res=0;
		rep(i,n+1) res+=x, x/=2;
		return res;
	};

	lint ans=d;
	rep(n,61){ // 跳ね返る回数
		lint lo=(1LL<<n)-1,hi=d;
		if(lo>hi) continue;

		while(hi-lo>1){
			lint mi=(lo+hi)/2;
			if(dist(mi,n)<d) lo=mi;
			else             hi=mi;
		}
		if(dist(hi,n)==d) ans=min(ans,hi);
	}
	printf("%lld\n",ans);

	return 0;
}
