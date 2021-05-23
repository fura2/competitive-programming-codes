#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> x(n),y(n);
	rep(i,n) scanf("%lld%lld",&x[i],&y[i]);

	rep(i,n) if((x[i]+y[i]+x[0]+y[0])%2!=0) return puts("-1"),0;

	lint d=0;
	rep(i,n) d=max(d,abs(x[i])+abs(y[i]));

	lint t;
	for(t=0;(t*(t+1)/2+d)%2!=0||t*(t+1)/2<d;t++);
	printf("%lld\n",t);

	return 0;
}
