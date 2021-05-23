// Day 2: Fermat

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
	int p,n; scanf("%d%d",&p,&n);

	int cnt[10000]={};
	rep(x,p) cnt[modpow(x,n,p)]++;

	int ans=0;
	rep(a,p) rep(b,p) ans+=cnt[a]*cnt[b]*cnt[(a+b)%p];
	printf("%d\n",ans);

	return 0;
}
