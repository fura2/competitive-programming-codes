#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int f[128];
	rep(d,10) f['0'+d]=d;
	for(int c='A';c<='Z';c++) f[c]=10+c-'A';

	int n; scanf("%d",&n);
	lint ans=LLONG_MAX;
	rep(i,n){
		string s; cin>>s;
		int base=0;
		for(char c:s) base=max(base,f[c]+1);
		lint res=0;
		for(char c:s) res=res*base+f[c];
		ans=min(ans,res);
	}
	printf("%lld\n",ans);

	return 0;
}
