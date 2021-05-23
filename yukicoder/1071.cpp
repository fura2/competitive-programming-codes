#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n;
	lint k,x,y; scanf("%d%lld%lld%lld",&n,&k,&x,&y);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	rep(i,n) a[i]=(a[i]-1+k-1)/k;
	sort(a.begin(),a.end());

	vector<lint> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	lint ans=INF;
	if(cum[n]<=ans/x) ans=cum[n]*x;
	rep(i,n){
		lint cost1=a[i]*y;
		lint cost2=(cum[n]-cum[i+1]-(n-i-1)*a[i]);
		if(cost2>=INF/x) continue;
		cost2*=x;
		ans=min(ans,cost1+cost2);
	}
	printf("%lld\n",ans);

	return 0;
}
