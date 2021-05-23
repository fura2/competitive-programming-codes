#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		int n,i0,j0; scanf("%d%d%d",&n,&i0,&j0);
		lint d=min({i0,n-i0-1,j0,n-j0-1});
		lint ans=4*d*(n-d);
		if     (d==i0) ans+=j0-d;
		else if(d==n-j0-1) ans+=(n-2*d-1)+(i0-d);
		else if(d==n-i0-1) ans+=2*(n-2*d-1)+(n-d-j0-1);
		else               ans+=3*(n-2*d-1)+(n-d-i0-1);
		printf("%lld\n",ans);
	}
	return 0;
}
