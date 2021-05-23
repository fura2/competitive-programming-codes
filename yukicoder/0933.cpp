#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	if(count(a.begin(),a.end(),0LL)>0) return puts("0"),0;

	lint x=1;
	rep(i,n) x=a[i]%9*x%9;
	printf("%lld\n",x==0?9:x);

	return 0;
}
