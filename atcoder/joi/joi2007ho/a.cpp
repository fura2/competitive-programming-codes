#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	int ans=INT_MIN;
	rep(i,n-k+1) ans=max(ans,cum[i+k]-cum[i]);
	printf("%d\n",ans);

	return 0;
}
