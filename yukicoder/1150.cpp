#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,s,t; scanf("%d%d%d",&n,&s,&t); s--; t--;
	vector<int> a(3*n);
	rep(i,n) scanf("%d",&a[i]), a[n+i]=a[2*n+i]=a[i];

	vector<lint> cum(3*n+1);
	rep(i,3*n) cum[i+1]=cum[i]+a[i];

	s+=n; t+=n;
	if(t<s) t+=n;

	lint ans=-INF;
	rep(l,3*n){
		int r=l+(n+1)/2;
		if(s-(s-(t-n))/2<=l && r<=s+(t-s)/2+1){
			ans=max(ans,2*(cum[r]-cum[l])-cum[n]);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
