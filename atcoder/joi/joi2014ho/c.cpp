#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> cum(2*n+1);
	rep(i,2*n) cum[i+1]=cum[i]+a[i%n];

	lint lo=0,hi=cum[2*n];
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		bool ok=false;
		int r1=0,r2=0;
		rep(l,n){
			while(r1-l<n && cum[r1]-cum[l]<mi) r1++;
			if(cum[r1]-cum[l]<mi) continue;

			r2=max(r2,r1);
			while(r2-l<n && cum[r2]-cum[r1]<mi) r2++;

			if(cum[r2]-cum[r1]>=mi && cum[l+n]-cum[r2]>=mi){
				ok=true;
				break;
			}
		}
		if(ok) lo=mi;
		else   hi=mi;
	}
	printf("%lld\n",lo);

	return 0;
}
