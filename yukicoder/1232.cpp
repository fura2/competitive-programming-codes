#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int p; scanf("%d",&p);
	printf("%lld\n",p==2?2:(p-1LL)*(p-1LL));
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
