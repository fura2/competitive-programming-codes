#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint modinv(lint a,lint m){
	lint b=m,u=1,v=0;
	while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
	return (u+m)%m;
}

lint modpow(lint a,lint k,int m){
	lint r=1;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

constexpr int MOD=1000003;

int main(){
	vector<lint> fact(MOD);
	fact[0]=1;
	rep(i,MOD-1) fact[i+1]=fact[i]*(i+1)%MOD;

	int q; scanf("%d",&q);
	rep(_,q){
		lint x,d,n; scanf("%lld%lld%lld",&x,&d,&n);

		lint ans;
		if(x==0){
			ans=0;
		}
		else if(d==0){
			ans=modpow(x,n,MOD);
		}
		else{
			lint p=modinv(d,MOD)*x%MOD;
			if(p+n-1>=MOD){
				ans=0;
			}
			else{
				ans=fact[p+n-1]*modinv(fact[p-1],MOD)%MOD;
				ans=ans*modpow(d,n,MOD)%MOD;
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
