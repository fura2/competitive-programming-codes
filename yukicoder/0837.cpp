#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	if(a[0]==a[n-1]){
		puts("1");
		return 0;
	}

	vector<lint> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+a[i];

	lint ans=INF;
	for(int i=1;i<n;i++){
		lint cost=0,tar;

		tar=a[i/2];
		cost+=(i/2+1)*tar-sum[i/2+1];
		cost+=(sum[i]-sum[i/2+1])-(i-i/2-1)*tar;

		tar=a[i+(n-i)/2];
		cost+=((n-i)/2+1)*tar-(sum[i+(n-i)/2+1]-sum[i]);
		cost+=(sum[n]-sum[i+(n-i)/2+1])-(n-i-(n-i)/2-1)*tar;

		ans=min(ans,cost);
	}
	printf("%lld\n",ans);

	return 0;
}
