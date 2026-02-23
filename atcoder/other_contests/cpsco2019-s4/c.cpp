#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,d; scanf("%d%d",&n,&d);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	lint ans=0;
	int r=0;
	rep(i,n){
		while(r<n && a[r]<=a[i]+d) r++;
		ans+=(r-i-1LL)*(r-i-2)/2;
	}
	printf("%lld\n",ans);

	return 0;
}
