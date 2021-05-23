#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<lint> hist(2e5+1);
	rep(i,n){
		int a; scanf("%d",&a);
		hist[a]++;
	}

	if(x>2e5) return puts("0"),0;

	lint ans=0;
	rep(i,x+1) ans+=hist[i]*hist[x-i];
	printf("%lld\n",ans);

	return 0;
}
