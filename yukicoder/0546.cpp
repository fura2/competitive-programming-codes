#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

int main(){
	int choose[11][11]={};
	rep(i,11) choose[i][0]=1;
	rep(i,10) rep(j,i+1) choose[i+1][j+1]=choose[i][j]+choose[i][j+1];

	int n;
	lint l,r; scanf("%d%lld%lld",&n,&l,&r);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	int coef[11];
	for(int i=2;i<=n;i++){
		coef[i]=i;
		for(int j=2;j<i;j++) coef[i]-=choose[i][j]*coef[j];
	}

	lint ans=0;
	rep(S,1<<n) if(S!=0) {
		lint L=1;
		rep(i,n) if(S>>i&1) L=min(lcm(L,a[i]),r+1);
		int pc=popcount(S);
		if(pc==1){
			ans+=r/L-(l-1)/L;
		}
		else{
			ans-=coef[pc]*(r/L-(l-1)/L);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
