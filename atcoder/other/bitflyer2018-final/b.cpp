#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> x(n);
	rep(i,n) scanf("%lld",&x[i]);

	vector<lint> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]+x[i];

	rep(_,q){
		lint c,d; scanf("%lld%lld",&c,&d);
		int i1=lower_bound(x.begin(),x.end(),c-d)-x.begin();
		int i2=lower_bound(x.begin(),x.end(),c)-x.begin();
		int i3=lower_bound(x.begin(),x.end(),c+d)-x.begin();

		lint res=0;
		res+=(cum[i3]-cum[i2])-c*(i3-i2);
		res+=c*(i2-i1)-(cum[i2]-cum[i1]);
		res+=d*(n-(i3-i1));
		printf("%lld\n",res);
	}

	return 0;
}
