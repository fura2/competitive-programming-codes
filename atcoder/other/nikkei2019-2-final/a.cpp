#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=0;
	rep(i,n){
		lint l=0,r=0;
		rep(j,i) if(a[j]<a[i]) l++;
		for(int j=i+1;j<n;j++) if(a[i]>a[j]) r++;
		ans+=l*r;
	}
	printf("%lld\n",ans);

	return 0;
}
