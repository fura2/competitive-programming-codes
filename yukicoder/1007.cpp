#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k); k--;
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	if(a[k]==0) return puts("0"),0;

	lint lsum=0,rsum=0;
	for(int i=k-1;i>=0;i--){
		lsum+=a[i];
		if(a[i]<=1) break;
	}
	for(int i=k+1;i<n;i++){
		rsum+=a[i];
		if(a[i]<=1) break;
	}

	if(a[k]==1) printf("%lld\n",a[k]+max(lsum,rsum));
	else        printf("%lld\n",a[k]+lsum+rsum);

	return 0;
}
