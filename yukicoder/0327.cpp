#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	int m=1;
	lint a=1;
	while(26*a<=n){
		a*=26;
		n-=a;
		m++;
	}

	string ans(m,'?');
	rep(i,m){
		ans[m-i-1]='A'+n%26;
		n/=26;
	}
	cout<<ans<<'\n';

	return 0;
}
