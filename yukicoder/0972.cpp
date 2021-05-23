#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	vector<lint> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	lint ans=0;
	rep(i,n){
		int lo=0,hi=n;
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(mi>0 && n-mi>i && i-mi>=0 && a[n-mi]+a[i-mi]-2*a[i]>=0) lo=mi;
 			else hi=mi;
		}
		ans=max(ans,cum[n]-cum[n-lo]+a[i]+cum[i]-cum[i-lo]-(2*lo+1)*a[i]);
	}
	printf("%lld\n",ans);

	return 0;
}
