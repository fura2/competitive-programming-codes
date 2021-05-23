#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		lint d,x,t; scanf("%lld%lld%lld",&d,&x,&t);
		long double ans=1;
		rep(i,d-1){
			ans*=x+i+1;
			ans/=i+1;
		}
		puts(ans<t+0.5?"AC":"ZETUBOU");
	}
	return 0;
}
