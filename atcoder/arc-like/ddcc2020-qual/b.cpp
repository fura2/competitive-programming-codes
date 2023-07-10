#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+a[i];

	lint ans=INF;
	rep(i,n-1){
		lint left=sum[i+1];
		lint right=sum[n]-left;
		ans=min(ans,abs(right-left));
	}
	printf("%lld\n",ans);

	return 0;
}
