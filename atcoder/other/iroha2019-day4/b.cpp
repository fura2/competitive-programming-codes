#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m;
	lint l; cin>>n>>m>>l;

	lint ans=m*l;
	rep(i,n){
		lint a,b; cin>>a>>b;
		ans=min(ans,a+m*b);
	}
	cout<<ans<<'\n';

	return 0;
}
