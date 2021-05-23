#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> inc(n+1),dec(n+1);
	rep(i,n){
		inc[i+1]=inc[i]+(a[i]<=a[i+1]?1:0);
		dec[i+1]=dec[i]+(a[i]>=a[i+1]?1:0);
	}

	int q; scanf("%d",&q);
	rep(_,q){
		int l,r; scanf("%d%d",&l,&r);
		printf("%d %d\n",inc[r]-inc[l]==r-l?1:0,dec[r]-dec[l]==r-l?1:0);
	}

	return 0;
}
