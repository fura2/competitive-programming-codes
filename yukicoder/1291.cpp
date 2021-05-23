#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n; scanf("%d",&n);
	if(n==1) puts("10");
	else     cout<<"9"<<string(n-1,'0')<<'\n';
}
int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
