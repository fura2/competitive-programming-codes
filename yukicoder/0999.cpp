#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(2*n);
	rep(i,2*n) scanf("%d",&a[i]);

	lint total=accumulate(a.begin(),a.end(),0LL);

	vector<lint> lsum(2*n+1),rsum(2*n+1);
	rep(i,2*n){
		lsum[i+1]=lsum[i]+(i%2==0?a[i]:0);
	}
	for(int i=2*n;i>0;i--){
		rsum[i-1]=rsum[i]+(i%2==0?a[i-1]:0);
	}

	lint res=0;
	rep(i,n+1) res=max(res,lsum[2*i]+rsum[2*i]);
	printf("%lld\n",2*res-total);

	return 0;
}
