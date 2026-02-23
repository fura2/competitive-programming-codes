#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int f(int n,int p){
	int res=0;
	while(n>=p) res+=n/p, n/=p;
	return res;
}

void solve(){
	int p,x; scanf("%d%d",&p,&x);

	if(p==2){
		printf("%lld\n",(1LL<<x)-1);
	}
	else{
		int n;
		for(n=0;n-f(n,p)!=x;n++);
		printf("%d\n",n);
	}
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
