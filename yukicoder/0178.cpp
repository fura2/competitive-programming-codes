#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> c(n);
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b);
		c[i]=a+4*b;
	}
	rep(i,n) if(c[i]%2!=c[0]%2) return puts("-1"),0;

	lint ans=0;
	lint mx=*max_element(c.begin(),c.end());
	rep(i,n) ans+=(mx-c[i])/2;
	printf("%lld\n",ans);

	return 0;
}
