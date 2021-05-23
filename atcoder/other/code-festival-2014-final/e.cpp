#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> dp1(n,1),dp2(n,1);
	for(int i=1;i<n;i++){
		rep(j,i) if(a[j]<a[i]) dp1[i]=max(dp1[i],dp2[j]+1);
		rep(j,i) if(a[j]>a[i]) dp2[i]=max(dp2[i],dp1[j]+1);
	}

	int ans=0;
	rep(i,n) ans=max({ans,dp1[i],dp2[i]});
	printf("%d\n",ans>=3?ans:0);

	return 0;
}
