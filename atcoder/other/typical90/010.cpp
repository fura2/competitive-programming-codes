#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector cum(2,vector(n+1,0));
	rep(i,n){
		int t,p; scanf("%d%d",&t,&p); t--;
		cum[t][i+1]=p;
	}
	rep(t,2) rep(i,n) cum[t][i+1]+=cum[t][i];

	int q; scanf("%d",&q);
	rep(_,q){
		int l,r; scanf("%d%d",&l,&r); l--;
		printf("%d %d\n",cum[0][r]-cum[0][l],cum[1][r]-cum[1][l]);
	}

	return 0;
}
