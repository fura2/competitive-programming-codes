#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	lint ans=0;
	rep(j,n) if((a[j]&k)==a[j]) ans+=b[j];

	rep(i,30) if(k>>i&1) {
		int x=(k|(1<<i)-1)&~(1<<i);
		lint sum=0;
		rep(j,n) if((a[j]&x)==a[j]) sum+=b[j];
		ans=max(ans,sum);
	}
	printf("%lld\n",ans);

	return 0;
}
