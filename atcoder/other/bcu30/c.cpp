#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	bool A[300][300]={};
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b); a--; b--;
		A[a][b]=true;
	}

	lint ans=0;
	rep(i,n) rep(j,n) {
		int cnt=0;
		rep(k,n) if(A[i][k] && A[k][j]) cnt++;
		ans+=cnt*cnt;
	}
	printf("%lld\n",ans);

	return 0;
}
