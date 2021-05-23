#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	lint a,b,c; scanf("%lld%lld%lld",&a,&b,&c);
	lint x=100*a+10*b+c;
	if(x%2==1){
		puts("No");
	}
	else{
		x/=2;
		if(a>0) x-=min(x,100*a)/100*100;
		if(b>0) x-=min(x,10*b)/10*10;
		if(c>0) x-=min(x,c);
		puts(x==0?"Yes":"No");
	}
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
