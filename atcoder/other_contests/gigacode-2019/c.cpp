#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
using lint=long long;

using namespace std;

const long long INF=1LL<<61;

int main(){
	int d; scanf("%d",&d);
	vector<lint> a(d),b(d);

	rep(i,d) scanf("%lld",&a[i]);
	rep(i,d) scanf("%lld",&b[i]);

	lint sum=0,ans=INF;
	rep(i,d){
		sum+=a[i];
		if(b[i]<=sum) ans=min(ans,b[i]);
	}
	printf("%lld\n",ans<INF?ans:-1);

	return 0;
}
