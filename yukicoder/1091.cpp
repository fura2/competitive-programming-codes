#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> cum(n+1);
	rep(i,n) cum[i+1]=cum[i]^a[i];

	rep(_,q){
		int l,r; scanf("%d%d",&l,&r); l--;
		printf("%d\n",cum[r]^cum[l]);
	}

	return 0;
}
