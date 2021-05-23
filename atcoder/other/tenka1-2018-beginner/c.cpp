#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	sort(a.begin(),a.end());

	if(n%2==0){
		lint ans=0;
		rep(i,n){
			if     (i< n/2-1) ans-=2*a[i];
			else if(i==n/2-1) ans-=a[i];
			else if(i==n/2  ) ans+=a[i];
			else              ans+=2*a[i];
		}
		printf("%lld\n",ans);
	}
	else{
		lint ans1=0;
		rep(i,n){
			if     (i<n/2-1) ans1-=2*a[i];
			else if(i<n/2+1) ans1-=a[i];
			else             ans1+=2*a[i];
		}
		lint ans2=0;
		rep(i,n){
			if     (i<n/2  ) ans2-=2*a[i];
			else if(i<n/2+2) ans2+=a[i];
			else             ans2+=2*a[i];
		}
		printf("%lld\n",max(ans1,ans2));
	}

	return 0;
}
