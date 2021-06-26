#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	string s; cin>>n>>s;

	lint ans=0;
	rep(i,n){
		ans+=lint(s[i]-'a')<<i;
	}
	printf("%lld\n",ans);

	return 0;
}
