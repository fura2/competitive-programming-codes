#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint a; scanf("%d%lld",&n,&a);
	vector<lint> x(n);
	rep(i,n) scanf("%lld",&x[i]);

	puts(accumulate(x.begin(),x.end(),0LL)==n*a?"YES":"NO");

	return 0;
}
