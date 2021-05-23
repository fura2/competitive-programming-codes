#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	lint nu=1,de=1;
	rep(i,n){
		int a; scanf("%d",&a);
		if(i==0) nu*=a;
		else     de*=a;
	}
	int m; scanf("%d",&m);
	rep(i,m){
		int b; scanf("%d",&b);
		if(i%2==0) de*=b;
		else       nu*=b;
	}
	lint g=gcd(nu,de);
	nu/=g;
	de/=g;
	if(de<0) nu*=-1, de*=-1;
	printf("%lld %lld\n",nu,de);
	return 0;
}
