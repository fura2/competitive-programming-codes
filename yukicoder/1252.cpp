#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint f(lint x,lint d){
	lint q=x/(d-1);
	lint r=x%(d-1);
	return d*(d-1)/2*q+r*(r+1)/2;
}

void solve(){
	int d,a,b; scanf("%d%d%d",&d,&a,&b);
	printf("%lld\n",f(b,d)-f(a==0?0:a-1,d));
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
