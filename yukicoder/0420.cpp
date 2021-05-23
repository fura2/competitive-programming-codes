#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint comb[40][40]={};
	rep(n,40){
		comb[n][0]=1;
		for(int r=1;r<=n;r++) comb[n][r]=comb[n-1][r-1]+comb[n-1][r];
	}

	int x; scanf("%d",&x);
	if(x>31) puts("0 0");
	else     printf("%lld %lld\n",comb[31][x],x==0?0:comb[30][x-1]*((1LL<<31)-1));
	return 0;
}
