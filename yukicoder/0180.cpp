#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	auto f=[&](lint x){
		lint mx=-INF,mn=INF;
		rep(i,n){
			mx=max(mx,a[i]+b[i]*x);
			mn=min(mn,a[i]+b[i]*x);
		}
		return mx-mn;
	};

	lint lo=1,hi=1e9;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		if(f(mi)<=f(mi+1)) hi=mi;
		else               lo=mi;
	}
	printf("%lld\n",f(lo)<=f(hi)?lo:hi);

	return 0;
}
