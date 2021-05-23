#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	vector<lint> cum2(n+1),cum3(n+1);
	rep(i,n){
		cum2[i+1]=cum2[i]+cum[i+1];
		cum3[n-i-1]=cum3[n-i]+cum[n]-cum[n-i-1];
	}

	lint ans=INF;
	for(int i=0;i<n;i+=2) ans=min(ans,cum2[i]+cum3[i+1]+i*(i-1LL)/2+(n-i-2)*(n-i-1LL)/2);
	printf("%lld\n",ans);

	return 0;
}
