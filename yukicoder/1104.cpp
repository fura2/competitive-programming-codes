#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	if(n==1) return puts("0"),0;

	vector<lint> res(n);
	for(int i=1;i<n;i++){
		res[i]=res[i-1]+a[i-1]+b[i];
		if(i>=2) res[i]=min(res[i],res[i-2]+a[i-2]+b[i]+k);
	}
	printf("%lld\n",max(res[n-2],res[n-1]));

	return 0;
}
