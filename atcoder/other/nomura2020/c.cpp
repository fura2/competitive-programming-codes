#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n+1);
	rep(d,n+1) scanf("%d",&a[d]);

	lint sum=0;
	rep(d,n+1) sum+=a[d];

	lint ans=0,f=1;
	rep(d,n+1){
		if(f-a[d]<0){
			return puts("-1"),0;
		}
		ans+=f;
		sum-=a[d];
		f=min(2*(f-a[d]),sum);
	}
	printf("%lld\n",ans);

	return 0;
}
