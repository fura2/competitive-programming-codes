#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	lint A[46]={},B[46]={},C[46]={};
	rep(i,n){ int a; scanf("%d",&a); A[a%46]++; }
	rep(i,n){ int b; scanf("%d",&b); B[b%46]++; }
	rep(i,n){ int c; scanf("%d",&c); C[c%46]++; }

	lint ans=0;
	rep(a,46) rep(b,46) rep(c,46) if((a+b+c)%46==0) ans+=A[a]*B[b]*C[c];
	printf("%lld\n",ans);

	return 0;
}
