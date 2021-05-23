#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector a(n,vector(3,0));
	rep(i,n) rep(j,3) scanf("%d",&a[i][j]);

	vector<int> ans(n);
	rep(i,n) rep(j,3) {
		bool ok=true;
		rep(k,n) if(k!=i && a[i][j]==a[k][j]) ok=false;
		if(ok) ans[i]+=a[i][j];
	}
	rep(i,n) printf("%d\n",ans[i]);

	return 0;
}
