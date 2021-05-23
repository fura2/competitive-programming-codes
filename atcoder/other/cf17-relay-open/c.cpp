#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k;
	scanf("%d%lld",&n,&k);
	vector<lint> w(n),d(n);
	rep(i,n) scanf("%lld%lld",&w[i],&d[i]);

	lint lo=0,hi=2e18;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		lint cnt=0;
		rep(i,n) if(w[i]<=mi) cnt+=1+(mi-w[i])/d[i];
		if(cnt<k) lo=mi;
		else      hi=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
