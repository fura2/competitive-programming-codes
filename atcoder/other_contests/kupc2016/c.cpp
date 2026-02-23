#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n,d; scanf("%d%d",&n,&d);

	int ans=0;
	rep(i,n-1){
		ans+=127;
		d^=127;
	}
	ans+=d;
	printf("%d\n",ans);
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
