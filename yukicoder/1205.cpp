#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	lint t=0;
	int p=0;
	rep(i,m){
		lint t2;
		int p2; scanf("%lld%d",&t2,&p2);
		if(abs(p2-p)>t2-t){
			puts("No");
			return 0;
		}
		t=t2;
		p=p2;
	}
	puts("Yes");

	return 0;
}
