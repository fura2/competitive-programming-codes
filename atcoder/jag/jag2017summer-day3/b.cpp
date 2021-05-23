#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x0,tar;
	int n; scanf("%lld%lld%d",&x0,&tar,&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	lint mn=0,sum=0;
	rep(i,n){
		sum+=a[i];
		mn=min(mn,sum);
		if(x0+sum<=tar){
			printf("%d\n",i+1);
			return 0;
		}
	}

	if(sum>=0){
		puts("-1");
		return 0;
	}

	// x0 + k*sum + mn <= tar
	// k >= (tar-x0-mn)/sum
	lint k=(-(tar-x0-mn)-sum-1)/(-sum);
	lint sum2=0;
	rep(i,n){
		sum2+=a[i];
		if(x0+k*sum+sum2<=tar){
			printf("%lld\n",k*n+i+1);
			return 0;
		}
	}

	return 0;
}
