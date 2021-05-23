#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,a[16]; scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);

	lint mx[16],mn[16];
	mx[0]=mn[0]=a[0];
	for(int i=1;i<n;i++){
		mx[i]=max({mx[i-1]+a[i],mx[i-1]-a[i],mx[i-1]*a[i],mn[i-1]+a[i],mn[i-1]-a[i],mn[i-1]*a[i]});
		mn[i]=min({mx[i-1]+a[i],mx[i-1]-a[i],mx[i-1]*a[i],mn[i-1]+a[i],mn[i-1]-a[i],mn[i-1]*a[i]});
		if(a[i]!=0){
			mx[i]=max({mx[i],mx[i-1]/a[i],mn[i-1]/a[i]});
			mn[i]=min({mn[i],mx[i-1]/a[i],mn[i-1]/a[i]});
		}
	}
	printf("%lld\n",mx[n-1]);

	return 0;
}
