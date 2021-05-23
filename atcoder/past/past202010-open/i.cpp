#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(2*n);
	rep(i,n){
		scanf("%lld",&a[i]);
		a[n+i]=a[i];
	}

	vector<lint> cum(2*n+1);
	rep(i,2*n) cum[i+1]=cum[i]+a[i];

	lint ans=INF;
	rep(i,n){
		int idx=lower_bound(cum.begin()+i,cum.end(),cum[n]/2+cum[i])-cum.begin();
		ans=min(ans,abs(2*(cum[idx]-cum[i])-cum[n]));
		if(idx>0){
			ans=min(ans,abs(2*(cum[idx-1]-cum[i])-cum[n]));
		}
	}
	printf("%lld\n",ans);

	return 0;
}
