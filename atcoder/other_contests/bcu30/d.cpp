#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> x(n);
	rep(i,n) scanf("%lld",&x[i]);

	vector cum(n+1,0LL);
	rep(i,n) cum[i+1]=cum[i]+x[i];

	rep(_,q){
		lint c; scanf("%lld",&c);
		int i=lower_bound(x.begin(),x.end(),c)-x.begin();
		printf("%lld\n",(i*c-cum[i])+(cum[n]-cum[i]-(n-i)*c));
	}

	return 0;
}
