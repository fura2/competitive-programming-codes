#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,a;
	int b; scanf("%lld%lld%d",&n,&a,&b);
	vector<lint> d(b);
	rep(i,b) scanf("%lld",&d[i]);

	d.emplace_back(0);
	d.emplace_back(n+1);
	b+=2;
	sort(d.begin(),d.end());

	lint ans=0;
	rep(i,b-1){
		ans+=(d[i+1]-d[i]-1)-(d[i+1]-d[i]-1)/a;
	}
	printf("%lld\n",ans);

	return 0;
}
