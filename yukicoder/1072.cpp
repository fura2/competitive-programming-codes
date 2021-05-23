#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<int> a(n);
	map<int,int> f;
	rep(i,n) scanf("%d",&a[i]), ++f[a[i]];

	lint ans=0;
	rep(i,n){
		int z=x^a[i];
		if(z==a[i]) ans+=f[z]-1;
		else        ans+=f[z];
	}
	ans/=2;
	printf("%lld\n",ans);

	return 0;
}
