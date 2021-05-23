#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint m; cin>>m;

	lint ans=1;
	rep(i,128) ans=ans*2%m;
	cout<<ans<<'\n';

	return 0;
}
