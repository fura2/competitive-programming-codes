#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a[26];
	rep(i,26) scanf("%lld",&a[i]);

	lint ans=1,tmp;
	ans*=a['h'-'a'];
	ans*=a['e'-'a'];
	ans*=a['w'-'a'];
	ans*=a['r'-'a'];
	ans*=a['d'-'a'];
	tmp=0;
	rep(i,a['l'-'a']+1) tmp=max(tmp,i*(i-1)/2*(a['l'-'a']-i));
	ans*=tmp;
	tmp=0;
	rep(i,a['o'-'a']+1) tmp=max(tmp,i*(a['o'-'a']-i));
	ans*=tmp;
	printf("%lld\n",ans);

	return 0;
}
