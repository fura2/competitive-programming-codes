#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint p,q; scanf("%d%lld%lld",&n,&p,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	if((p+q)%2!=0) return puts("0"),0;
	lint a1=(p+q)/2;

	lint ans=0,cnt=0;
	map<lint,int> f;
	for(int i=n-1;i>=0;i--){
		if(a[i]==a1){
			ans+=cnt;
		}
		cnt+=f[(p-q)/2-a[i]];
		++f[a[i]];
	}
	printf("%lld\n",ans);

	return 0;
}
