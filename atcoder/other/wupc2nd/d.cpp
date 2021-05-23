#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c,d,e; cin>>a>>b>>c>>d>>e;

	lint ans=0;

	ans+=e;
	e=0;

	ans+=d;
	a-=min((125-64)*d,a);
	d=0;

	ans+=c;
	lint tmp=(125-27)*c;
	tmp-=8*min(7*c,b);
	b-=min(7*c,b);
	a-=min(tmp,a);
	c=0;

	ans+=(b+7)/8;
	tmp=125*((b+7)/8)-8*b;
	a-=min(tmp,a);
	b=0;

	ans+=(a+124)/125;
	a=0;

	printf("%lld\n",ans);

	return 0;
}
