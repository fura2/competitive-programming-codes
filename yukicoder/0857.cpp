#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x,y,z; cin>>x>>y>>z;
	lint ans=z;
	if(x<=z) ans--;
	if(y<=z) ans--;
	cout<<ans<<'\n';
	return 0;
}
