#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int m,n; scanf("%d%d",&m,&n);

	lint ans;
	switch(m){
		case 0: ans=n+1; break;
		case 1: ans=2+(n+3)-3; break;
		case 2: ans=2*(n+3)-3; break;
		case 3: ans=(1LL<<(n+3))-3; break;
	}
	printf("%lld\n",ans);

	return 0;
}
