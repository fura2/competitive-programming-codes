#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint p,q,r,a,b,c; cin>>p>>q>>r>>a>>b>>c;
	lint L=max({p*(a-1),q*(a+b-1),r*(a+b+c-1)});
	lint R=min({p*a,q*(a+b),r*(a+b+c)});
	if(L<R) printf("%lld %lld\n",L+1,R);
	else puts("-1");
	return 0;
}
