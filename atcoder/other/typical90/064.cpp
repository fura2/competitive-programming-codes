#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> d(n-1);
	rep(i,n-1) d[i]=a[i]-a[i+1];

	lint ans=0;
	rep(i,n-1) ans+=abs(d[i]);
	rep(_,q){
		int l,r;
		lint v; scanf("%d%d%lld",&l,&r,&v); l--;
		if(0<=l-1 && l-1<n-1){ ans-=abs(d[l-1]); d[l-1]-=v; ans+=abs(d[l-1]); }
		if(0<=r-1 && r-1<n-1){ ans-=abs(d[r-1]); d[r-1]+=v; ans+=abs(d[r-1]); }
		printf("%lld\n",ans);
	}

	return 0;
}
