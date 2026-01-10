#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,m; cin>>n>>m;
	lint ans=1;
	rep(i,min(n,m)) ans=ans*(i+1)%m;
	cout<<ans<<'\n';
	return 0;
}
