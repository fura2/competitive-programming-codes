#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,d; scanf("%d%d",&n,&d);
	rep(i,n) scanf("%*d");

	lint vsum=0;
	rep(i,n){
		int v; scanf("%d",&v);
		vsum+=v;
	}

	printf("%lld\n",(d+vsum-1)/vsum);

	return 0;
}
