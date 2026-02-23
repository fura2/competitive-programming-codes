#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=998244353;

lint xgcd(lint a,lint b,lint &x,lint &y){
	if(b==0){ x=1; y=0; return a; }
	lint g=xgcd(b,a%b,y,x); y-=a/b*x;
	return g;
}

lint modinv(lint a,lint m){
	lint x,y;
	if(xgcd(a,m,x,y)==1) return (x+m)%m;
	return -1;
}

lint inv[200001],fact[200001],factinv[200001];

lint Catalan(int n){
	return fact[2*n]*factinv[n]%MOD*factinv[n]%MOD*inv[n+1]%MOD;
}

int main(){
	int n;
	string s; cin>>n>>s;

	fact[0]=factinv[0]=1;
	rep(i,2*n+1){
		inv[i+1]=modinv(i+1,MOD);
		fact[i+1]=fact[i]*(i+1)%MOD;
		factinv[i+1]=factinv[i]*inv[i+1]%MOD;
	}

	lint ans=1;
	int pre=0;
	rep(i,n) if(i==n-1 || s[i]!=s[i+1]) {
		ans=ans*Catalan(i-pre+1)%MOD;
		pre=i+1;
	}
	cout<<ans<<endl;

	return 0;
}

// experiment
/*
	int n,p[30]; cin>>n;
	rep(i,2*n) p[i]=i;

	int cnt=0;
	do{
		bool ok=true;
		rep(i,n-1){
			if(p[i]>p[i+1]) ok=false;
			if(p[n+i]>p[n+i+1]) ok=false;
		}
		rep(i,n){
			if(p[i]>p[n+i]) ok=false;
		}
		if(ok){
			cnt++;
			rep(i,2*n) printf("%d ",p[i]+1); puts("");
		}
	}while(next_permutation(p,p+2*n));
	printf("%d\n",cnt);
*/
