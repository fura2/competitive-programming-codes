#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	/*
			/ a b c \
		A = | d e f |
			\ 0 0 1 /
	*/
	lint a,b,c,d,e,f;
	puts("? 0 0");
	fflush(stdout);
	scanf("%lld%lld",&c,&f);
	puts("? 1 0");
	fflush(stdout);
	scanf("%lld%lld",&a,&d);
	a-=c; d-=f;
	puts("? 0 1");
	fflush(stdout);
	scanf("%lld%lld",&b,&e);
	b-=c; e-=f;

	puts("!");
	rep(i,n) printf("%lld %lld\n",a*x[i]+b*y[i]+c,d*x[i]+e*y[i]+f);
	fflush(stdout);

	return 0;
}
