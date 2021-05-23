#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint modpow(lint a,lint k,int m){
	lint r=1;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

int main(){
	int x,n; scanf("%d%d",&x,&n);

	lint ans=0;
	rep(i,n){
		int a; scanf("%d",&a);
		ans+=modpow(x,a,1000003);
	}
	printf("%lld\n",ans%1000003);

	return 0;
}
