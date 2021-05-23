#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> x(n);
	rep(i,n) scanf("%lld",&x[i]);

	sort(x.begin(),x.end());

	lint ans=0,sum=0;
	rep(i,n){
		ans+=i*x[i]-sum;
		sum+=x[i];
	}
	printf("%lld\n",ans);

	return 0;
}
